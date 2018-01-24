/*
说明：
在工程中在App的初始化列表中，初始化了N个对象，结果某个对象初始化异常，App的constructor没有执行。
Custom* 就是自定义的复杂类，添加一个dummy变量来调试定位哪个初始化异常。
初始化列表初始顺序是声明的顺序，移动dummy的声明顺序来定位custrom对象。
*/
//小技巧，很有用

int test()
{
    std::cout << "this is a test" << std::endl;

    return 0;
}

class A
{
public:
    Custom x;
    Custom1 y;

    int dummy;

    A(int _1, int _2) : x(_1), y(_2), dummy(test())
    {
        std::cout << "Constructor not end" << std::endl;
    }
};

int main()
{
    A a(c1,c2);
}
