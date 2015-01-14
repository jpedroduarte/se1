#include "Timer.h"
#include "LPC2xxx.h"
#include "LPC2106.h"

/* Iniciação do sistema para permitir o acesso ao periférico Timer 0. O timer
é iniciado em modo continuo e à frequência indicada no parâmetro frequency. */
void TMR0_Init(unsigned int frequency){
	if(frequency > LPC2106_PCLK || frequency == 0) return;
	LPC2106_BASE_TC0.IR= 0x00000000;
	LPC2106_BASE_TC0.TCR= 0x00000002;
	LPC2106_BASE_TC0.TC;			//Overflow counter
	LPC2106_BASE_TC0.PR = LPC2106_PCLK/frequency - 1;//Maximum value possible for the Prescale Counter
	//LPC2106_BASE_TC0.PC; 							//Prescale Counter
	LPC2106_BASE_TC0.MCR=	0x0000000;				//Match Control Register- Feature Disabled
	//LPC2106_BASE_TC0.MR0;							//Match Register- Not used
	//LPC2106_BASE_TC0.MR1;							//Match Register- Not used
	//LPC2106_BASE_TC0.MR2;							//Match Register- Not used
	//LPC2106_BASE_TC0.MR3;							//Match Register- Not used
	LPC2106_BASE_TC0.CCR= 0x00000000;				//Capture Control Register - Feature Disabled
	//LPC2106_BASE_TC0.CR0;							//Capture Register
	//LPC2106_BASE_TC0.CR1;							//Capture Register
	//LPC2106_BASE_TC0.CR2;							//Capture Register
	//LPC2106_BASE_TC0.CR3;							//Capture Register
	LPC2106_BASE_TC0.EMR= 0x00000000;				//External Match Register- Do Nothing
	//LPC2106_BASE_TC0.RESERVED[12]; 				/* Dummy */
	LPC2106_BASE_TC0.CTCR= 0;			            //Counter mode: TC incremented every rising edge
	LPC2106_BASE_TC0.TCR= 0x00000001;				//Enable Counter
}

/* Devolve o valor corrente do Timer 0 em unidades de contagem (ticks). */
unsigned int TMR0_GetValue(void){
	return LPC2106_BASE_TC0.TC;
}

/* Devolve o valor, em unidades de contagem (ticks), desde o lastRead até o
tempo corrente. */
unsigned int TMR0_Elapsed(unsigned int lastRead){
	 unsigned int now= TMR0_GetValue();
	 return now-lastRead;
}

void TMR0_Delay(unsigned t){
	unsigned now = TMR0_GetValue();
	while(TMR0_Elapsed(now) < t);
}
