//From :https://lists.boost.org/Archives/boost/att-189469/weak_fn.hpp

//There is no content to preview.

#ifndef BOOST_WEAK_FN_HPP
#define BOOST_WEAK_FN_HPP

#include <memory>
#include <iostream>

namespace std {

struct ignore_if_invalid { void operator()() const {} };

template <typename V = void>
struct throw_if_invalid {
    V operator()() const {
        throw std::bad_weak_ptr();
    }
};

template <typename V>
struct return_default_if_invalid {
    return_default_if_invalid(): def_value_() {}
    return_default_if_invalid(V def_value): def_value_(def_value) {}

    V operator()() const {
        return def_value_;
    }

private:
    V def_value_;
};

typedef ignore_if_invalid default_invalid_policy;

} // namespace std

namespace std { 
namespace detail {

template<typename T, typename R, typename Policy, typename... Args>
class weak_fn_storage {
public:
    typedef R result_type;

    weak_fn_storage(
            R (T::*mem_fn)(Args...),
            const std::weak_ptr<T>& ptr,
            Policy policy)
        : mem_fn_(mem_fn)
        , ptr_(ptr)
        , policy_(policy)
    {}

    R operator()(Args... args)
    {
        if (std::shared_ptr<T> ptr = ptr_.lock()) {
            std::cout << "lock ok" << std::endl;
            return ((*ptr).*mem_fn_)(args...);
        } else {
            std::cout << "lock not ok" << std::endl;
 //           return policy_();
        }
    }

private:
    R (T::*mem_fn_)(Args...);
    std::weak_ptr<T> ptr_;
    Policy policy_;
};

} // namespace detail

/** Returns a callback that can be used eg. in std::bind. When called, it
 * tries to lock weak_ptr to get a shared_ptr. If successful, it calls
 * given member function with given arguments. If not successful, it calls given
 * policy functor. Built-in policies are:
 *
 * "ignore_if_invalid" - does nothing
 * "throw_if_invalid" - throws "bad_weak_ptr"
 * "return_default_if_invalid" - returns given value
 *
 * Example:
 *
 * struct Foo {
 *     void bar(int i) {
 *         std::cout << i << std::endl;
 *     }
 * };
 *
 * struct do_something {
 *     void operator()() {
 *         std::cout << "outdated reference" << std::endl;
 *     }
 * };
 *
 * int main()
 * {
 *     std::shared_ptr<Foo> sp(new Foo());
 *     std::weak_ptr<Foo> wp(sp);
 *
 *     std::bind(std::weak_fn(&Foo::bar, wp), _1)(1);
 *     sp.reset();
 *     std::bind(std::weak_fn(&Foo::bar, wp), 1)();
 *     std::bind(std::weak_fn(&Foo::bar, wp, do_something()), 1)();
 * }
 */
template <typename T, typename R, typename Policy, typename... Args>
detail::weak_fn_storage<T, R, Policy, Args...> weak_fn(
        R (T::*mem_fn)(Args...),
        const std::weak_ptr<T>& ptr,
        Policy policy)
{
    return detail::weak_fn_storage<T, R, Policy, Args...>
        (mem_fn, ptr, policy);
}

template <typename T, typename R, typename... Args>
detail::weak_fn_storage<T, R, default_invalid_policy, Args...> weak_fn(
        R (T::*mem_fn)(Args...),
        const std::weak_ptr<T>& ptr)
{
    return detail::weak_fn_storage<T, R, default_invalid_policy, Args...>
        (mem_fn, ptr, default_invalid_policy());
}

} // namespace std

#endif

