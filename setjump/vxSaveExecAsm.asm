
global SaveExecAsm


SaveExecAsm:
    




    mov qword [rdi + 4], rax
    mov qword [rdi + 8], rbx
    mov qword [rdi + 12], rcx
    mov qword [rdi + 16], rdx
    mov qword [rdi + 20], rsi
    mov qword [rdi + 24], rsp
    mov qword [rdi + 28], rbp

    
    ret