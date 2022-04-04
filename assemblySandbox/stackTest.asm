global stackTest

section .text

stackTest:
	
	;enter
	push rbp
	mov rbp, rsp
	
	shufps xmm0, xmm1, 00101000b
	shufps xmm0, xmm0, 11000101b
	shufps xmm2, xmm3, 00100010b
	shufps xmm2, xmm2, 11010000b
	shufps xmm0, xmm2, 11101110b
	
	lea rax, [rel increment]
	movups xmm1, [rax]
	addps xmm0, xmm1
	
	lea rax, [rel temp]

	movss xmm4, xmm0
	movss [rax], xmm4
	fld dword [rax]

	leave
	ret

section .bss 
	
	result: resb 128
	temp: resb 32

section .data
	increment: dd 1.0, 1.0, 1.0, 1.0
	