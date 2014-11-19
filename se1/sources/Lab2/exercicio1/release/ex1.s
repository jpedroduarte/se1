.data

.equ A, 10
.equ B, 5
.equ C, 13
.equ D, 3

result_c: 
	.word
	.word

.text

.globl div


	
div:	
	cmp r1, #0
	beq _zero
	mov r2, #0
_while:	
	cmp r0, r1
	blo _endcicle
	
	sub r0, r0, r1
	add r2, r2, #1
	b _while
_zero:
	mov r0, #-1
	b _fim
_endcicle:
	mov r0, r2
_fim:
	mov r15,r14
	
	
	
div_c:
	cmp r2, #0
	beq _zero_c
	mov r3, #0
_while_c:	
	cmp r1, r2
	blo _endcicle_c
	
	sub r1, r1, r2
	add r3, r3, #1
	b _while_c
_zero_c:
	mov r1, #-1
	
_endcicle_c:
	stm r0, { r1,r3}
	
_fim_c:
	mov r15,r14
	
.end
	
