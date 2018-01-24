#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
class A
{
public:
    int x;

    bool operator< (const A& a) const
    {
        return x < a.x;
    }
};

int main()
{
    A a;
    a.x = 10;

    A b;
    b.x = 9;

    A c;
    c.x = 8;
    
    std::vector<A> v{a,b,c};

    std::sort(std::begin(v), std::end(v));

    for(auto& _ : v)
    {
        std::cout << _.x << std::endl;
    }

    std::sort(std::begin(v), std::end(v), std::less<A>());

    for(auto& _ : v)
    {
        std::cout << _.x << std::endl;
    }
}
