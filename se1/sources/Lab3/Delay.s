.text

.globl Delay

Delay:
_main_loop:
	mov r1, #3680
	mul r2,r0,r1
_inside_loop:
	mov r0, #0
	sub r2,r2, #1
	cmp r0,r2
	bne _inside_loop
_end:	
	mov r15, r14
.end
