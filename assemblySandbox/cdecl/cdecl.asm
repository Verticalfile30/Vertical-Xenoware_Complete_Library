global fpuTest

section .data

section .bss
    arg1: resd 1
section .text

fpuTest:
    fstp dword [rel arg1]
    ret