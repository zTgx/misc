#include <typeinfo> //typeid

typedef std::conditional<true, int, double>::type T;
std::cout << typeid(T).name() << std::endl;
