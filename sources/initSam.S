
/*
 * init.S
 *
 *  Created on: 14 Oct 2010
 *      Author: psampaio
 */

/*****************************************************************
	Module includes the interrupt vectors and start-up code.
 ******************************************************************/

.section .startup, "ax"

.global _start

ResetHandler:
_start:
	ldr   	r0, =__stack_top__
	mov   	sp, r0

	/* Clear .bss section */
	ldr   	r1, =__bss_start__
	ldr   	r2, =__bss_end__
	ldr   	r3, =0
bss_clear_loop:
	cmp   	r1, r2
	strne 	r3, [r1], #+4
	bne   	bss_clear_loop

	/* Initialise .data section */
	/* In debug not necessary. */


	mov		fp, #0
	mov		r0, #0
	mov		r1, #0
	bl		main				/* enter main() */                

    b		.

/****************************************************************************/
/*                         Stack area                                       */
/****************************************************************************/
.section .stack
	.space	1024 * 2
__stack_top__:


.end
