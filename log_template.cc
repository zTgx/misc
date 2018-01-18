//Author : beautifularea
//Date   : 1/18/2018

#include <iostream>
#include <sstream>
#include <stdio.h>

/*
to be continued ...
formatter
sink
*/

#define IF_LOG_(severity) if(!detail::A::get().checkSeverity(severity)){;} else
#define LOG(severity) IF_LOG_(severity) (detail::A::get()) += detail::B::get() 

namespace detail {
inline void 
operator <<(std::ostream& stream, const char* data)
{
    std::operator<<(stream, data);
}

enum log_severity{
    trace,
    info,
    debug,
    warning,
    error,
    fatal
};

class B
{
private:
    std::ostringstream message;

public:
    static B& get()
    {
        static B b;
        return b;
    }
public:
    void print() const
    {
        printf("message = %s\n " ,  message.str().c_str());
    }
    
    template<typename T>
    B& operator<<(const T& data)
    {
        printf("template\n");

        using namespace detail;
        message << data;

        return *this;
    }
};

class A
{
private:
    log_severity m_severity;

public:
    void operator+=(B& red)
    {
        red.print();
    }
public:
    static A& get()
    {
        static A a;
        return a;
    }

    bool checkSeverity(log_severity severity)
    {
        return severity >= m_severity;
    }

    void set_severity(log_severity severity)
    {
        m_severity = severity;
    }
    log_severity get_severity()
    {
        return m_severity;
    }
};


static void init(log_severity sev)
{
    A::get().set_severity(sev);
}
} //end namespace

int main()
{
    detail::init(detail::warning);

    LOG(detail::info) << "info" << "info ok";
    LOG(detail::error) << "error" << " " << "error";
    LOG(detail::debug) << "XXX" << "YYY" << "ZZZ";
}
