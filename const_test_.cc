#include <iostream>

class Test
{
public:
    Test()
    {
        v_ = 3;
    }

public:
    int _1(const int t) const
    {
        return v_;
    }

    int _2(int t)
    {
        return v_;
    }

private:
    int v_;
};

int main()
{
    //non-object can call const-member function
    Test t;
    t._1(2);

    //Must have a user-defined constructor, if you define a const object , otherwise, there will be a compiler error!
    const Test t1;
    t1._1(2);

    //const object call non-const member function , will be a compiler error either.
    t1._2(3);
}
