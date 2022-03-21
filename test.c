#include <stdio.h>
#include <limits.h>
#include "vxBits.h"

int numArrLen(int *array) {
    
    int accum = 0;
    int length;
    for(int i = 1; array[accum] != (INT_MAX); i++) {
        accum++;
        length = i;
    }
    return length;
}

int main() {
    
    uint8_t num = 250;
    
    printf("%d\n", num);

    int mag = 7;
    int accessSaved;
    int arrayBitField[30];
    int realBitField[30];
    int arrayBitFieldLen;
    //num = toggleFlag(num, 7);

    for(int i = 0; i < 8; i++) {
        if(isFlagSet(num, i) == 1) {
            arrayBitField[i] = 1;
        } else {
            arrayBitField[i] = 0;
        }
        accessSaved = i + 1;
    }
    arrayBitField[accessSaved] = INT_MAX;

    arrayBitFieldLen = numArrLen(arrayBitField);


    for(int i = 0, j = arrayBitFieldLen - 1; i < arrayBitFieldLen || j > -1; i++, j--) {
        realBitField[i] = arrayBitField[j];
    }

    for(int i = 0; i < 8; i++) {
        printf("%d", realBitField[i]);
    }
    printf("\n");
    
    /*if (isFlagSet(num, mag) == 1) {
        printf("Flag %d is set \n", mag);
    } else {
        printf("Flag %d is not set\n", mag);
    }*/
    
    return 0; 
}
