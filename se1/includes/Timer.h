/** @file TIMER.h
 *  TIMER module header.
 */

#ifndef _TIMER_H_
#define _TIMER_H_

/** 
 * Faz a iniciação do sistema para permitir o acesso ao periférico Timer 0.
 * O timer deve ser iniciado em modo continuo.
 * @param frequency Define a frequecia aplicada ao Timer 0
*/
void TMR0_Init(unsigned int frequency);

/**
 * Devolve o valor corrente do Timer 0 em unidades de contagem (ticks). 
 * @return valor corrente
*/
unsigned int TMR0_GetValue(void);

/**
 * Devolve o valor desde o lastRead até o tempo corrente. 
 * @param lastRead Indica o tempo da ultima leitura.
 * @return valor, em unidades de contagem (ticks)
 */
unsigned int TMR0_Elapsed(unsigned int lastRead);

#endif

