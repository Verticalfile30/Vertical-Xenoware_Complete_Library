#include <stdint.h>
#include <limits.h>
#include "vxBits.h"

#define HIGH 1
#define LOW 2
#define INT 342420
#define SING_FLOAT 4
#define DOUBLE_FLOAT 510911
#define QUAD_FLOAT 6
#define BIG 910533





int numArrLen(int *array) {
    
    int acc = 0;
    int length;
    for(int i = 1; array[acc] != (INT_MAX); i++) {
        acc++;
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

/*=============================================================================
SYNOPSIS: REVERSES ANY GIVEN ARRAY 

ARGS: "BITFIELD": BITS TO BE MODIFIED | "BITMAGNITUDE": WHICH BIT WILL BE MODIFED

RETURN: BITFIELD AS INTEGER

ANOMALOUS CLASS: SAFE
 *===========================================================================*/
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

/*=============================================================================
SYNOPSIS: REVERSES ANY GIVEN ARRAY 

ARGS: "ARRAY": VOID POINTER TO GIVEN ARRAY | "LEN": DETERMINES TERMINATING LENGTH |
    "TYPE": DETERMINES DATA TYPE ARRAY.

RETURN: RETURNS A POINTER TO RESULTING ARRAY

ANOMALOUS CLASS: SAFE
 *===========================================================================*/
void *arrayReverser(void *array, int len, int type){
    if(type == INT) {
        static int result[32];
        int sentinel;
        int *intArray = array;
        for(int i = 0, j = len - 1; i < len || j > -1; i++, j--) {
            result[i] = intArray[j];
            sentinel = i;
        }
        result[sentinel + 1] = INT_MAX;

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

    return 0;
}

/*=============================================================================
SYNOPSIS: TAKES AN INTEGER LITERAL AND CONVERTS INTO A BIT FIELD. 

ARGS: "ARG": VOID POINTER TO THE LITERAL | "TYPE": DETERMINES WHAT KIND OF INTEGER TYPE |
    "ENDIAN_STYLE": DETERMINES IF LSB OR MSB SHOULD BE IN ACCESS [0].

RETURN: RETURNS A POINTER TO RESULTING ARRAY

ANOMALOUS CLASS: SAFE
 *===========================================================================*/
int32_t *literalToBitArray(void *arg, int type, int endianStyle) {
    if(type == INT) {
        int *integer = arg;
        static int intArray[32];
        int sentinelAccess;
        
        for(int i = 0; i < 32; i++) {
            if(isFlagSet(*integer, i) == 1) {
                intArray[i] = 1;
                sentinelAccess = i + 1;
            }
            intArray[sentinelAccess] = INT_MAX; 
        }

        if(endianStyle == BIG) {
            int *bigArray = arrayReverser(intArray, sentinelAccess, INT);
            return bigArray;
        }
        

        return intArray;
    }

    return 0;
}

int32_t singleToInt(float arg) {
    return *((int32_t*)&arg);
}

int32_t base10Array_toLiteral(char *array) {
    int endVal;
    //main procedure
    {
        int *pseudoPara = &endVal;
        for(int i = 0, mag = 1; array[i] != CHAR_MAX; i++, mag *= 10) {
            pseudoPara[i] = array[i] * mag;
        } 
    }

    return endVal;
}



/*=============================================================================
SYNOPSIS: Parses an integers from a string.
 *===========================================================================*/
int32_t integerParse(const char *string, int len) {
    char *filtered;
    int *resultArray;
    char filteredData[32];
    int resultData[32];
    int sentinel;
    int32_t result;

    //filter out non-numeric characters
    filtered = &filteredData[0];
    for(int i = 0, j = 0; i < len; i++) {
        if(string[i] >= 48 && string[i] <= 57) {
            filtered[j] = string[i];
            sentinel = j;
            j++;
        }
        
    }
    filtered[sentinel + 1] = CHAR_MAX;
    
    //convert every element by ascii things
    resultArray = &resultData[0];
    for(int i = 0; filtered[i] != CHAR_MAX; i++) {
        resultArray[i] = filtered[i] - 48;
        sentinel = i;
    }
    resultArray[sentinel + 1] = INT_MAX;

    resultArray = arrayReverser(resultArray, sentinel + 1, INT);

    //accumulate the integer
    for(int i = 0, mag = 1; resultArray[i] != INT_MAX; i++, mag *= 10) {
        result += resultArray[i] * mag;
    }

    return result;
}

/*=============================================================================
NOTE: THIS FUNCTION IS DEPRECATED. UNSAFE CLASSIFICATION: KETER
 *===========================================================================*/
/*singleFloat *floatingPointToBitArray(void *arg, const char *type) {
    //get type
    {
        if(type == "32") {
            static singleFloat bits;
            float *single = arg;
            int32_t singleAsInt = singleToInt(*single);
            
            //add mantissa to struct
            {
                int sentinelAccess;
                for(int i = 0; i < 23; i++) {
                    bits.mantissa[i] = isFlagSet(singleAsInt, i);
                    sentinelAccess = i + 1;
                }
                bits.mantissa[sentinelAccess] = CHAR_MAX;

                //add exponent to struct
                {
                    for(int i = 0; i < 23; i++) {
                        if(i < 23) {
                            continue;
                        } else if(i >= 23 && i < 32) {
                            bits.exponent[i - 23] = isFlagSet(singleAsInt, i);
                            sentinelAccess = i + 1;
                        }
                        bits.exponent[sentinelAccess] = CHAR_MAX;
                    }

                    //add sign bit
                    {
                        bits.sign = isFlagSet(singleAsInt, 31);
                    }

                    //return 
                    {
                        return &bits;
                    }

                }
            }
        }
    }

    //add bits to struct

    return 0;
}
*/
