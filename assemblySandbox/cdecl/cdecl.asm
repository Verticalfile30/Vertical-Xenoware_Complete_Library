global fpuTest

section .data

section .bss
    arg1: resd 1
    arg2: resd 1
section .text

fpuTest:
    ;this function will mov the values of xmm0 and xmm1 to the fpus
    movss [rel arg1], xmm0
    movss [rel arg2], xmm1
    fld dword [rel arg1]
    fld dword [rel arg2]
    
    fstp dword [rel arg1]
    fstp dword [rel arg2]

    ret