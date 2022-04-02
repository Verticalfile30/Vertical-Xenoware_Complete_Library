#ifndef VX_STDLIB_H
#define VX_STDLIB_H

#define ANON_ALLOC 010253
#define FILE_ALLOC 110253
#define CHARACTER 224631
#define INTEGER 342420
#define STRING 410894
#define DOUBLE 510911
#define PAGESIZE

#if (__STDC_VERSION__ != 201710L)
    #error "You are using the wrong standard :("
#endif

#ifndef __amd64__
#error "Only compilable on amd64 family of processors"
#endif

typedef struct pointer {
    int *inr;
    char *chr;
    unsigned long size;
} ptr;

/*
USER LEVEL FUNCTIONS ONLY
*/
int vxAllocChk(void *pointer);
int vxStdWrite(const char *string);

int vxStreamWrite(int fildes, const char *string, ...);
int vxCharWrite(char arg, int fd);

int vxNeoWrite(int fildes, const char *string, ...);

ptr *vxTypeAlloc(unsigned long sizeArg, int dataType, int fildes);
int vxTypeDealloc(ptr *object);

extern void *memoryAllocate();

#endif