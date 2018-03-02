#include <boost/intrusive/list.hpp>
#include <vector>
#include <iostream>

class T : public boost::intrusive::list_base_hook<>
{
public:
    int v_;

public:
    //explicit
    T(int v) : v_(v){}
};

int main()
{
    typedef boost::intrusive::list<T> listType;
    listType list;

    std::vector<T> v;
    for(int i=0;i<10;++i)
    {
        v.push_back(i);
    }

    for(auto iter=v.begin(); iter != v.end(); ++iter)
    {
        list.push_front(*iter);
    }

    listType::reverse_iterator iter(list.rbegin());

    for(;iter != list.rend(); ++iter)
    {
        //T t = *iter;
        std::cout << iter->v_ << "\t";
    }
    
    /*
    t: /usr/local/include/boost/intrusive/detail/generic_hook.hpp:47: 
    void boost::intrusive::detail::destructor_impl(Hook&, boost::intrusive::detail::link_dispatch<(boost::intrusive::link_mode_type)1u>) [with Hook = boost::intrusive::generic_hook<boost::intrusive::circular_list_algorithms<boost::intrusive::list_node_traits<void*> >, boost::intrusive::dft_tag, (boost::intrusive::link_mode_type)1u, (boost::intrusive::base_hook_type)1u>]: Assertion `!hook.is_linked()' failed.
    Aborted (core dumped)
    */
    list.clear(); //if not clear, occured a assert.
    //考虑link_mode的设置
    //http://www.boost.org/doc/libs/1_40_0/doc/html/boost/intrusive/link_mode_type.html
    //auto_unllik or normal_link

    for(auto iter=v.begin(); iter != v.end();)
    {
        iter = v.erase(iter);
        ++iter;      
    }
    std::cout << "size = " << v.size() << std::endl;
    std::cout << std::endl;
}
