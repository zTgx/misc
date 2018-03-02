#include <iostream>

class A
{
public:
    int v;

    virtual ~A()
    {
        std::cout << "~A" << std::endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        std::cout << "~B" << std::endl;
    }
};

int main()
{
    B b;

    //敲黑板！！！
    //if ~A() is not virutal , memory leak will be accur.
    A* a = new B;
    delete a;
}
