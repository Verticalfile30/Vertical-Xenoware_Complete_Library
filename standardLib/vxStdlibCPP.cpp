#include "vxStdlib.h"
#include "vxStdlibCPP.hpp"
#include <stdarg.h>
#include <stdio.h>

static int ioServices::vxStdWriteCPP(const char *string) {
    return vxStdWrite(string);
}

static int ioServices::vxStreamWriteCPP(int fildes, const char *string, ...) {
    va_list args;
    va_start(args, string);
    return vxStreamWriteArgs(fildes, string, args);
}

static int ioServices::vxCharWriteCPP(char arg, int fd) {
    return vxCharWrite(arg, fd);
}

static int memoryServices::vxAllocChkCPP(void *pointer) {
    return vxAllocChk(pointer);
}

static void *memoryServices::vxAllocCPP(unsigned long sizeArg, int map, int fildes) {
    return vxAlloc(sizeArg, map, fildes);
}

static int memoryServices::vxDeallocCPP(void *ptr, unsigned long int sizeArg) {
    return vxDealloc(ptr, sizeArg);
}