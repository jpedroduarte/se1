.global _start

.data
	res_l: .word 0x3
	
.text

_start:
	ldr r0, =res_l
	adds r0,r0,r2
	adcs r1,r1,r3

.end
