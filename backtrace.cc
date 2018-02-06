#include <iostream>
#include <mutex>
#include <atomic>
#include <exception>
#include <vector>
#include <string>
#include <iterator>
#include <memory>
#include <execinfo.h>

namespace zh
{
    void fatalerror(const std::string& message, const std::string& filename, int line);
}

void
zh::fatalerror(const std::string& message,
               const std::string& filename,
               int line)
{
    static std::atomic<int> c(0);
    static std::recursive_mutex mutex;

    std::lock_guard<std::recursive_mutex> lock(mutex);

    if(c++ != 0)
        return std::terminate();

    std::cerr << "\033[31m" << "An error has occurred, The application will terminate.\n";
    std::cerr << "\033[0m";

    if(message.length() != 0)
        std::cerr << "Message = " << message << std::endl;

    if(filename.length() != 0)
        std::cerr << "FileName = " << filename << " at line " << line << std::endl;

    try {
    std::vector<std::string> stacks;
    void* data[128];
    int frames = backtrace (data, std::distance(std::begin(data), std::end(data)));

    std::unique_ptr<char*[], void(*)(void*)> frame (backtrace_symbols (data, frames), std::free);

    for (int i = 0; i < frames; ++i)
    {
        stacks.push_back (frame[i]);
    }

    if(!stacks.empty())
    {
        std::cerr  << "Stacks : " << std::endl;

        for(auto& frame : stacks)
        {
            std::cerr << frame << std::endl;
        }
    }
    } catch (...)
    {}

    return std::terminate();
}
