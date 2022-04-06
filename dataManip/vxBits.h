/*
C HEADER FILE
*/

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#ifndef VX_BITS_H
#define VX_BITS_H

#ifdef __cplusplus
extern "C" {
#endif
//#if (__STDC_VERSION__ != 201710L)
//    #error "You are using the wrong standard :("
//#endif

//#ifndef __amd64__
//#error "Only compilable on amd64 family of processors"
//#endif

typedef struct sf{
    int8_t mantissa[23];
    int8_t exponent[8];
    int8_t sign;
} singleFloat;



uint32_t setFlag(uint32_t bitFlag, uint8_t bitMagnitude);

uint32_t toggleFlag(uint32_t bitFlag, uint8_t bitMagnitude);

bool isFlagSet(uint32_t bitFlag, uint8_t bitMagnitude);
int numArrLen(int *array);
uint32_t bitMask(uint32_t bitField, uint8_t bitMagnitude, uint8_t option);
const void *arrayReverser(void *array, int len, int type);
int32_t *literalToBitArray(void *arg, int type, int endianStyle);
singleFloat *floatingPointToBitArray(void *arg, const char *type);
int32_t integerParse(const char *string, int len);

#ifdef __cplusplus
}
#endif
#endif