#ifndef _TIMER_H_
#define _TIMER_H_

void TMR0_Init(unsigned int frequency);

unsigned int TMR0_GetValue(void);

unsigned int TMR0_Elapsed(unsigned int lastRead);

#endif

