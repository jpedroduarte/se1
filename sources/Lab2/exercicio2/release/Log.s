.data
.equ base, 3
.equ value, 9
result: .word

.text

.globl Log

Log:
	mov ip, sp
	stmfd sp!, {r4-r10, fp, ip, lr, pc}
	sub fp, ip, #4 
	mov r7, #0 @result
	mov r5, r0
	mov r6, r2
	cmp r1, #0
	bls _error	@menor ou igual jump
	cmp r6, #1
	beq _error
	cmp r6, #0
	blo _error
	mov r0, r1
	mov r1, r2
_cicle:
	add r7,r7,#1
	bl div
	cmp r0, r6
	blo _ret
	b _cicle
_error:
	mov r0, #-1
	b _end

_ret:
	str r7, [r5]
	mov r0, #1
_end:	
	ldmea fp, {r4-r10, fp, sp, pc}
	mov r15, r14
