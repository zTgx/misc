#include <cstring>
#include <string>

// ...

std::string x = "hello world";
char *y = new char[x.length() + 1]; // or
// char y[100];

std::strcpy(y, x.c_str());

delete[] y;
