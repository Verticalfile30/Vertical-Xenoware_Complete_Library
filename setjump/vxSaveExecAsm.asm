
global SaveExecAsm
global ReturnExecAsm

section .text
SaveExecAsm:
    
    mov qword [rdi + 4], rax
    mov qword [rdi + 8], rbx
    mov qword [rdi + 12], rcx
    mov qword [rdi + 16], rdx
    mov qword [rdi + 20], rsi
    mov qword [rdi + 24], rsp
    mov qword [rdi + 28], rbp
    
    lea rax, [rel returnLabel]
    
    mov qword [rdi + 32], rax

returnLabel:    ret

ReturnExecAsm:

    mov qword rax, [rdi + 4]
    mov qword rbx, [rdi + 8]
    mov qword rcx, [rdi + 12]
    mov qword rdx, [rdi + 16]
    mov qword rsi, [rdi + 20]
    mov qword rsp, [rdi + 24]
    mov qword rbp, [rdi + 28]
    
    mov qword rax, [rdi + 32]
    
    jmp rax