//----------------------server.h
#include <iostream>
#include <memory>

class virtual_base
{
public:
    virtual void set() = 0;
    virtual int get() = 0;

private:
    int v;
};

std::shared_ptr<virtual_base> make_Imp();


//-------------------------server.cc
#include "what.h"

//把实现类封装起来，只暴露virtual接口
class impl : public virtual_base
{
public:
    void set()
    {
        std::cout << "set" << std::endl;
    }

    int get()
    {
        std::cout << "get" << std::endl;
    }
};

std::shared_ptr<virtual_base> make_Imp()
{
    return std::make_shared<impl>();
}
------------------

//使用
#include "what.h"

int main()
{
    std::shared_ptr<virtual_base> ptr = make_Imp();
    ptr->set();
    ptr->get();
}


