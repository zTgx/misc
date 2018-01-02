#include <memory>

namespace std {

#if _cpluscplus >= 201305L
//supported cxx 14
#else
template <typename T, typename... Args>
std::unique_ptr<T> make_unique (Args&&... args)
{
    return std::unique_ptr<T> (new T(std::forward<Args>(args)...));
}
#endif

}
