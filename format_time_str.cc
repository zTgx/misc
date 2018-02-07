#include <ctime>

//%Y-%b-%d %H:%M:%S
std::time_t t = std::time(nullptr);

char mbuff[40];
std::strftime(mbuff, sizeof(mbuff), "%Y-%b-%d %H:%M:%S", std::localtime(&t));
std::cout << "mbuff = " << mbuff << std::endl;

//output
//mbuff = 2018-Feb-07 17:18:50
