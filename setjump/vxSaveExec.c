#include "../standardLib/vxStdlib.h"
#include <stdlib.h>


int SaveExec(void * buffer);
extern void SaveExecAsm(void * buffer);
extern void ReturnExecAsm(void * buffer);



int SaveExec(void * buffer) {
    SaveExecAsm(buffer);
    return 0;
}

int RestoreExec(void * buffer) {
    ReturnExecAsm(buffer);
    return 0;
}
