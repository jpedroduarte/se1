.globl _start

.section stack
.space 2048
__stack_top__:

_start:
	ldr sp, =__stack_top__
	mov fp, #0
	
	ldr r1, =__bss_start__
	ldr r2, =__bss_end__
	ldr r3, =0
bss_clean_loop:
	cmp r1, r2
	stmc r3, [r1], #4
	bne bss_clean_loop
	
	mov r0, #0
	mov r1, #0
	bl main
	b	.
	.end
