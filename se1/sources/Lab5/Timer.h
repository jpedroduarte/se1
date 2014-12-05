#ifndef _TIMER_H_
#define _TIMER_H_

#include "LPC2xxx.h"
#include "LPC2106.h“

void TMR0_Init(unsigned int frequency);

unsigned int TMR0_GetValue(void);

unsigned int TMR0_Elapsed(unsigned int lastRead);

#endif /* _TIMER_H_ */
