#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dataManip/vxBits.h"
#include "standardLib/vxStdlib.h"
#include "setjump/vxSaveExec.h"

int main() {
    
    //make an array
    /*int uggh = INTEGER;
    ptr *arr = vxTypeAlloc(sizeof(int32_t) * 10, uggh, 0);
    for(int i = 0; i < 10; i++) {
        arr->inr[i] = i;
    }
    for(int i = 0; i < 10; i++) {
        //vxStreamWrite(fileno(stdout), "", INTEGER, arr->inr[i], CHARACTER, '\n');
        //vxStreamWrite(fileno(stdout), "", INTEGER, arr->inr[i], STRING, " NeoWriter", CHARACTER, '\n');
    }

    arr->inr = arrayReverser(arr->inr, 10, INTEGER);

    for(int i = 0; i < 10; i++) {
        //vxStreamWrite(fileno(stdout), "", INTEGER, arr->inr[i], STRING, " StreamWriter", CHARACTER, '\n');
    }
    */
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
