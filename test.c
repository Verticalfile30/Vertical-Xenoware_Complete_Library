#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vxBits.h"
#include "standardLib/vxStdlib.h"

int main() {
    //make an array
    int uggh = INTEGER;
    ptr *arr = vxTypeAlloc(sizeof(int32_t) * 10, uggh, 0);
    for(int i = 0; i < 10; i++) {
        arr->inr[i] = i;
    }
    for(int i = 0; i < 10; i++) {
        vxStreamWrite(fileno(stdout), "", INTEGER, arr->inr[i], CHARACTER, '\n');
    }

    arr->inr = arrayReverser(arr->inr, 10, INTEGER);

        for(int i = 0; i < 10; i++) {
        vxStreamWrite(fileno(stdout), "", INTEGER, arr->inr[i], CHARACTER, '\n');
    }

    return 0;
}
