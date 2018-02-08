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
    
    list.clear();

    for(auto iter=v.begin(); iter != v.end();)
    {
        iter = v.erase(iter);
        ++iter;      
    }
    std::cout << "size = " << v.size() << std::endl;
    std::cout << std::endl;
}
