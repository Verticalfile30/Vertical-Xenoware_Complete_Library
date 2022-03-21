#include <stdint.h>
#include <limits.h>

#define HIGH 1
#define LOW 2
#define INT 3
#define SING_FLOAT 4
#define DOUBLE_FLOAT 5
#define QUAD_FLOAT 6


int numArrLen(int *array) {
    
    int accum = 0;
    int length;
    for(int i = 1; array[accum] != (INT_MAX); i++) {
        accum++;
        length = i;
    }
    return length;
}



uint32_t setFlag(uint32_t bitField, uint8_t bitMagnitude) {
    bitField |= (0b0000000000000001 << bitMagnitude);
    return bitField;
}

_Bool isFlagSet(uint32_t bitField, uint8_t bitMagnitude) {
    uint32_t testFlag = bitField >> bitMagnitude;
    
    
    if((testFlag % 2) == 1) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t toggleFlag(uint32_t bitField, uint8_t bitMagnitude) {
    bitField ^= (0b0000000000000001 << bitMagnitude);
    return bitField;
}

uint32_t bitMask(uint32_t bitField, uint8_t bitMagnitude, uint8_t option) {
    if(option == HIGH) {
        int bitMasker = bitField >> bitMagnitude;
        bitMasker = bitMasker << bitMagnitude;
        bitField ^= bitMasker;
        return bitField;
    } else {
        bitField = bitField >> bitMagnitude;
        return bitField;
    }
}

uint32_t *intArrayReverser(int *array, int len){
    int result[32];
    for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
        result[i] = array[j];
    }
    return result;
}

uint32_t *literalToArray(void *arg, int type) {
    if(type == INT) {
        int *integer = arg;
        int intArray[32];
        int sentinelAccess;
        
        for(int i = 0; i < 32; i++) {
            if(isFlagSet(*integer, i) == 1) {
                intArray[i] = 1;
                sentinelAccess = i + 1;
            }
            intArray[sentinelAccess] = INT_MAX; 
        }

        int bitArray = intArrayReverser(intArray, sentinelAccess);

        return bitArray;
    }
}