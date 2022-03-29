#include "../standardLib/vxStdlib.h"
#include <stdlib.h>



extern void SaveExecAsm(void * buffer);



int SaveExec(void * buffer) {
    SaveExecAsm(buffer);
    return 0;
}

int main() {
    void *driver = malloc(sizeof(int) * 30);
    SaveExec(driver);

    return 0;
}