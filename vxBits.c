#include <stdint.h>
#include <limits.h>

#define HIGH 1
#define LOW 2
#define INT 342420
#define SING_FLOAT 4
#define DOUBLE_FLOAT 510911
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

void *arrayReverser(void *array, int len, int type){
    if(type == INT) {
        static int result[32];
        int *intArray = array;
        for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
            result[i] = intArray[j];
        }
        return (void*)result;
    }
    if(type == SING_FLOAT) {
        static float result[32];
        float *singArray = array;
        for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
            result[i] = singArray[j];
        }
        return (void*)result;
    }
    if(type == DOUBLE_FLOAT) {
        static double result[32];
        double *doubleArray = array;
        for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
            result[i] = doubleArray[j];
        }
        return (void*)result;
    }
    if(type == QUAD_FLOAT) {
        static long double result[32];
        long double *quadArray = array;
        for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
            result[i] = quadArray[j];
        }
        return (void*)result;
    }
}

int32_t *literalToBitArray(void *arg, int type) {
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

        int *bitArray = arrayReverser(intArray, sentinelAccess, INT);

        return bitArray;
    }
}