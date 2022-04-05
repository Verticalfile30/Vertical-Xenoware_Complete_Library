#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dataManip/vxBits.h"
#include "standardLib/vxStdlib.h"
#include "setjump/vxSaveExec.h"

int main() {
    
    int **characterSheet = vxAlloc(sizeof(int *), ANON_ALLOC, -1);
    
    //make an array using vxAlloc
    characterSheet[0] = vxAlloc(sizeof(int), ANON_ALLOC, -1);

    char *stringVar = "HI 87654 BYE!";
    int32_t newString = integerParse(stringVar, 14);

    

    //vxStreamWrite(1, "", STRING, stringVar, CHARACTER, '\n');
    //vxStreamWrite(1, "", INTEGER, newString, CHARACTER, '\n');
    //printf("%s\n", stringVar);
    //printf("%d\n", newString);

    //void *buffer = malloc(sizeof(int32_t) * 10);
    //SaveExec(buffer);
    //RestoreExec(buffer);
    //free(buffer);

    void *bufferNew = memoryAllocate();
    char *charBuffer = bufferNew;
    
    scanf("%s", charBuffer);

    //vxStreamWrite(1, "", STRING, charBuffer, CHARACTER, '\n');

    printf("%s\n", charBuffer);

    return 0;
}
