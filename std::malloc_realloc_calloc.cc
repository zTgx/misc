
//std::alloc 内部

#include <cstdlib>
#include <cstring> //std::memset

//Allocates size bytes of uninitialized storage.
int *r = (int*)std::malloc(sizeof(int) * 4);
std::memset(dest, 0, 4) 

//Reallocates the given area of memory. It must be previously allocated by std::malloc(), std::calloc() or std::realloc() and not yet freed with std::free(), otherwise, the results are undefined.
r = (int*)std::realloc(r, 5); //5 	new size of the array

//Allocates memory for an array of num objects of size size and initializes it to all bits zero
int *p = (int*)std::calloc(num, sizeof(int));

std::free(r)
