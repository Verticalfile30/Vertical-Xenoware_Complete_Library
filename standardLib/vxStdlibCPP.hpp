#ifndef VX_STDLIB_CPP_H
#define VX_STDLIB_CPP_H
#include <stdarg.h>

extern "C" {

class ioServices {
public:
    static int vxStdWriteCPP(const char *string);

    static int vxStreamWriteCPP(int fildes, const char *string, ...);
    static int vxCharWriteCPP(char arg, int fd);
};

class memoryServices { 
public:
    int vxAllocChkCPP(void *pointer);
    void *vxAllocCPP(unsigned long sizeArg, int map, int fildes);
    int vxDeallocCPP(void *ptr, unsigned long int sizeArg);
};
}

#endif