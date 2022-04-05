global memoryAllocate

section .text

memoryAllocate:
    lea rax, [rel buffer]
    ret

section .bss
buffer: resb 1
