#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "vxStdlib.h"

#define ANON_ALLOC 010253
#define FILE_ALLOC 110253
#define CHARACTER 224631
#define INTEGER 342420
#define STRING 410894
#define DOUBLE 510911
#define PAGESIZE




int vxAllocChk(void *pointer) {
    if(pointer == (void *)-1 || pointer == NULL) {
        vxStreamWrite(1, "Allocation Failed.\n");
        return -1;
    }
    else {
        return 1;
    }
}

void *vxAlloc(unsigned long sizeArg, int map, int fildes) {
    
    if(map == ANON_ALLOC) {
        void *pointer = mmap(NULL, sizeArg, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if(vxAllocChk(pointer) == 1) {
            return pointer;
        }
    }
    else if(map == FILE_ALLOC) {
        void *pointer = mmap(NULL, sizeArg, PROT_READ | PROT_WRITE, MAP_SHARED, fildes, 0);
        if(vxAllocChk(pointer) == 1) {
            return pointer;
        }
    }

    return (void *)-1;
}

int vxDealloc(void *ptr, unsigned long int sizeArg) {
    if(munmap(ptr, sizeArg) == -1) {
        vxStdWrite("Deallocation failed.\n");
        return -1;
    }
    else {
        return 1;
    }
}

int vxStdWrite(const char *stringMessage) {
    int stdoutFD = fileno(stdout);
    write(stdoutFD, stringMessage, strlen(stringMessage));
    return 1;
}

int vxIntWrite(int arg, int fd) {
    dprintf(fd, "%d", arg);
    return 1;
}

int vxDouWrite(double arg, int fd) {
    dprintf(fd, "%lf", arg);
    return 1;
}

int vxCharWrite(char arg, int fd) {
    dprintf(fd, "%c", arg);
    return 1;
}

/*=============================================================================
SYNOPSIS: WRITES TO STDOUT 

RETURN: INTEGER CODE FOR SUCCESS

NOTE: ~~vxNeoWrite DEEMED UNSAFE, IT HAS BEEN RECLASSIFIED AS EUCLID, 
vxStreamWrite IS CONSIDERED THE SAFER OPTION~~

**MEMORY CORRUPTION ISSUES HAVE BEEN REPORTED THROUGHOUT THE ENTIRE LIBRARY, 
UNTIL FURTHER NOTICE, **DO NOT USE THE OUTPUT OR OUTPUT RELATED PROCEDURES.***

ANOMALOUS CLASS: KETER
*===========================================================================*/
int vxStreamWrite(int fildes, const char *string, ...) {

    //va_list *list = vxAlloc(sizeof(va_list) * 30, ANON_ALLOC, -1); //allocate an array of 
    va_list list[30];

    va_start(list[0], string);
    va_copy(list[1], list[0]);
    int nargN;
    char nargC;
    double nargD;
    char *nargS;

    vxStdWrite(string);

    

    for(int i = 0; i < 28 ; i++) {
        va_copy(list[i + 2], list[i + 1]); //store the previous argument, if successful, "i" increments and the current argument is stored
        if((nargN = va_arg(list[i + 2], int)) == INTEGER) { //va_arg acts like an increment
            nargN = va_arg(list[i + 2], int);
            vxIntWrite(nargN, fildes);
            continue;

        } 
        va_copy(list[i + 2], list[i + 1]);
        if ((nargN = va_arg(list[i + 2], int)) == CHARACTER) {
            nargC = (char)va_arg(list[i + 2], int);
            vxCharWrite(nargC, fildes);
            continue;

        }
        va_copy(list[i + 2], list[i + 1]);
        if ((nargN = va_arg(list[i + 2], int)) == DOUBLE) {
            nargD = va_arg(list[i + 2], double);
            vxDouWrite(nargD, fildes);
            continue;

        }
        va_copy(list[i + 2], list[i + 1]);     
        if ((nargN = va_arg(list[i + 2], int)) == STRING) {
            nargS = va_arg(list[i + 2], char *);
            vxStdWrite(nargS);
            continue;

        }
    }

    
    return 1;
}


va_list *argIncrement(va_list *argList, int increment) {
    int tmp;
    //va_list *newArgList = argList;
    for(int i = 1; i <= increment; i++) {
        tmp = va_arg(*argList, int);
    }
    return argList;
}

/*=============================================================================
SYNOPSIS: WRITES TO STDOUT 

RETURN: INTEGER CODE FOR SUCCESS

ANOMALOUS CLASS: EUCLID

NOTE: COUNCIL DEBATING ON RELIABILITY, EXPECT TO BE ARCHIVED AND DEPRECATED
WITHIN ONE MONTH.
*===========================================================================*/
int vxNeoWrite(int fildes, const char *string, ...) {
    
    va_list list[2];
    va_list *currentList;

    va_start(list[0], string);
    int nargN;
    char nargC;
    double nargD;
    char *nargS;

    for(int i = 0; i < 28; i++) {
        va_copy(list[1], list[0]);
        currentList = &list[1];
        currentList = argIncrement(currentList, i);
        
        
        if((nargN = va_arg(*currentList, int) == INTEGER)) {
            i++;
            va_copy(list[1], list[0]);
            currentList = &list[1];
            currentList = argIncrement(currentList, i);
            nargN = va_arg(*currentList, int);
            //i++;
            vxIntWrite(nargN, fildes);
            continue;
        }
        va_copy(list[1], list[0]);
        currentList = &list[1];
        currentList = argIncrement(currentList, i);        

        if((nargN = va_arg(*currentList, int) == CHARACTER)) {
            i++;
            va_copy(list[1], list[0]);
            currentList = &list[1];
            currentList = argIncrement(currentList, i);
            nargC = (char)va_arg(*currentList, int);
            vxCharWrite(nargC, fildes);
            continue;
        }
        va_copy(list[1], list[0]);
        currentList = &list[1];
        currentList = argIncrement(currentList, i);

        if((nargN = va_arg(*currentList, int) == STRING)) {
            i++;
            va_copy(list[1], list[0]);
            currentList = &list[1];
            currentList = argIncrement(currentList, i);
            nargS = va_arg(*currentList, char *);
            vxStdWrite(nargS);
            continue;
        }
        va_copy(list[1], list[0]);
        currentList = &list[1];
        currentList = argIncrement(currentList, i);

        if((nargN = va_arg(*currentList, int) == DOUBLE)) {
            i++;
            va_copy(list[1], list[0]);
            currentList = &list[1];
            currentList = argIncrement(currentList, i);
            nargD = va_arg(*currentList, double);
            vxDouWrite(nargD, fildes);
            continue;
        }
        va_copy(list[1], list[0]);
        currentList = &list[1];
        currentList = argIncrement(currentList, i);        
    }

    return 1;
}


void *memoryAllocateDriver() {
    void *result = memoryAllocate();
    return result;
}

/*
*===========================================================================*
* FUNCTION: vxTypeAlloc
*
* DESCRIPTION: This function really sucks
*
* RETURN: ptr type
*===========================================================================*/
ptr *vxTypeAlloc(unsigned long sizeArg, int dataType, int fildes) {
    
    if(dataType == INTEGER) {
        ptr *object = vxAlloc(sizeof(ptr), ANON_ALLOC, -1);
        object->inr = vxAlloc(sizeArg, ANON_ALLOC, -1);
        object->size = sizeArg;
        return object;

    } else if(dataType == CHARACTER) {
        ptr *object = vxAlloc(sizeof(ptr), ANON_ALLOC, -1);
        object->chr = vxAlloc(sizeArg, ANON_ALLOC, -1);
        object->size = sizeArg;
        return object;
    }

    return -1;
}

int vxTypeDealloc(ptr *object) {
    vxDealloc(object->inr, object->size);
    vxDealloc(object->chr, object->size);
    vxDealloc(object, sizeof(ptr));
    return 1;
} 

