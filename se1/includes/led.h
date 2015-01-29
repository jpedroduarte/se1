/** @file LED.h
*  LED module header.
*/
#ifndef LED_H
#define LED_H

/**
* Faz a iniciação do sistema para permitir a manipulação do estado LED
* @param pinID pino a que o led se encontra ligado
* @param state ON != 0 OFF == 0
*/
void LED_Init(int pinId, int state);

/**
* Devolve o estado do led
* @return 0 se o LED está apagado e um valor diferente de zero no caso
contrário
*/
int LED_GetState(void);

/**
* Altera o estado do led
* @param state apaga o LED se state = 0 ou acende o LED no caso contrário.
*/
void LED_SetState(int state);

#endif
