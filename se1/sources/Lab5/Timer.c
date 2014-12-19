#include "Timer.h"

/* Iniciação do sistema para permitir o acesso ao periférico Timer 0. O timer
é iniciado em modo continuo e à frequência indicada no parâmetro frequency. */
void TMR0_Init(unsigned int frequency){
	if(frequency > LPC2106_PCLK) return;
	TIMER0.IR= 0x00000000;
	TIMER0.TCR= 0x00000000;
	TIMER0.TC;							//Overflow counter
	TIMER0.PR= LPC2106_PCLK/frequency; 	//Maximum value possible for the Prescale Counter
	TIMER0.PC; 							//Prescale Counter
	TIMER0.MCR=	0x0000000;				//Match Control Register- Feature Disabled
	TIMER0.MR0;							//Match Register- Not used
	TIMER0.MR1;							//Match Register- Not used
	TIMER0.MR2;							//Match Register- Not used
	TIMER0.MR3;							//Match Register- Not used
	TIMER0.CCR= 0x00000000;				//Capture Control Register - Feature Disabled
	TIMER0.CR0;							//Capture Register
	TIMER0.CR1;							//Capture Register
	TIMER0.CR2;							//Capture Register
	TIMER0.CR3;							//Capture Register
	TIMER0.EMR= 0x00000000;				//External Match Register- Do Nothing
	TIMER0.RESERVED[12]; 				/* Dummy */
	TIMER0.CTCR= 0; 			        //Counter mode: TC incremented every rising edge
}

/* Devolve o valor corrente do Timer 0 em unidades de contagem (ticks). */
unsigned int TMR0_GetValue(void){
	return TIMER0.TC;
}

/* Devolve o valor, em unidades de contagem (ticks), desde o lastRead até o
tempo corrente. */
unsigned int TMR0_Elapsed(unsigned int lastRead){
	 unsigned int now= TMR0_GetValue();
	 return now-lastRead;
}
