template <bool isConst, typename T>
struct maybe_const
{
    typedef
    typename std::conditional<isConst, 
                              typename std::remove_const<T>::type const,
                              typename std::remove_const<T>::type>::type
    type;
};

template <bool isConst, typename T>
using maybe_const_t = typename maby_const<isConst, T>::type;

//Usage:
//void post(typename maybe_const<isConst, listtype>::type& list)
//{ do_something(); }
//
//void post(maybe_const_t<isConst, listtype>& list)
//{ do_something(); }
