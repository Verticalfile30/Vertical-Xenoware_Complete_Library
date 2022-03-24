#include <stdint.h>
#include <limits.h>

#ifndef VX_BITS_H
#define VX_BITS_H

#if (__STDC_VERSION__ != 201710L)
    #error "You are using the wrong standard :("
#endif

#ifndef __amd64__
#error "Only compilable on amd64 family of processors"
#endif

typedef struct sf{
    int8_t mantissa[23];
    int8_t exponent[8];
    int8_t sign;
} singleFloat;

uint32_t setFlag(uint32_t bitFlag, uint8_t bitMagnitude);

uint32_t toggleFlag(uint32_t bitFlag, uint8_t bitMagnitude);

_Bool isFlagSet(uint32_t bitFlag, uint8_t bitMagnitude);
int numArrLen(int *array);
uint32_t bitMask(uint32_t bitField, uint8_t bitMagnitude, uint8_t option);
void *arrayReverser(void *array, int len, int type);
int32_t *literalToBitArray(void *arg, int type, int endianStyle);
singleFloat *floatingPointToBitArray(void *arg, const char *type);

#endif