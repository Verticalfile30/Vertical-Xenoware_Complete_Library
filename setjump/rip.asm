
global ugh

section .text

ugh:

    lea rax, [rel test]
    ret


section .data
test: db 'hello', 0