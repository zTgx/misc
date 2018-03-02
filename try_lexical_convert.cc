#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>
#include <string>

class input {
public:
    int value;

    friend
    inline std::istream& operator>>(std::istream& in, input& put)
    {
        in >> put.value;
        return in;
    }
};

class output {
public:
    int s;
    int ss;
    friend
    inline std::ostream& operator<<(std::ostream& out, const output& put)
    {
        out << put.s;
        return out;
    }
};

int main()
{
    input in;
    output ou;

    if(boost::conversion::try_lexical_convert(ou, in))
    {
        std::cout << "lexical cast success." << std::endl;
    }
    else
    {
        std::cout << "lexical cast fail." << std::endl;
    }
}

//ALERT！！！！
//try_lexical_cast(ou, in)
//convert [ou] to [in]
















