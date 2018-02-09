#include <iostream>

class A
{
public:
    void f()
    {
        std::cout << "A's foo" << std::endl;
    }
};

class B : public  virtual A
{
public:
};

class C : public virtual A
{
public:
};

class D : public B , public C
{
public:
    void f()
    {
        A::f();

        std::cout << "D's foo" << std::endl;
    }
};

int main()
{
    D d;
    d.f();
}
