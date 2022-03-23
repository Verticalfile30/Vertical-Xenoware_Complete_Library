#include <stdint.h>
#include <limits.h>

#ifndef VX_BITS_H
#define VX_BITS_H

uint32_t setFlag(uint32_t bitFlag, uint8_t bitMagnitude);

uint32_t toggleFlag(uint32_t bitFlag, uint8_t bitMagnitude);

_Bool isFlagSet(uint32_t bitFlag, uint8_t bitMagnitude);
int numArrLen(int *array);
uint32_t bitMask(uint32_t bitField, uint8_t bitMagnitude, uint8_t option);
void *arrayReverser(void *array, int len, int type);
int32_t *literalToBitArray(void *arg, int type);

#endif