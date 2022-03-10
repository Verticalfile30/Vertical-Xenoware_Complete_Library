#include <stdint.h>

uint32_t setFlag(uint32_t bitFlag, uint8_t bitMagnitude) {
    bitFlag |= (0b0000000000000001 << bitMagnitude);
    return bitFlag;
}

_Bool isFlagSet(uint32_t bitFlag, uint8_t bitMagnitude) {
    uint32_t testFlag = bitFlag >> bitMagnitude;
    
    
    if((testFlag % 2) == 1) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t toggleFlag(uint32_t bitFlag, uint8_t bitMagnitude) {
    bitFlag ^= (0b0000000000000001 << bitMagnitude);
    return bitFlag;
}