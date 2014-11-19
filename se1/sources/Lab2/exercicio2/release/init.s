.text

.global _start

_start:
	ldr sp, =__stack_top__
	bl crt_init
	mov r0, #0
	mov r1, #0
	bl main
	b .

.section .stack
.space 2048
__stack_top__:
