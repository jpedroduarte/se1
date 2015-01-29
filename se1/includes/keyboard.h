/** @file KEYBOARD.h
*  KEYBOARD module header.
*/
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

/**
* Faz a iniciação do sistema para permitir o acesso ao periférico. 
* @param layout vetor com os códigos das 16 teclas
*/
void KBD_Init(unsigned int layout[16]);

/**
* Verifica se uma tecla foi precionada
* @return 1 se existe alguma tecla pressionada e 0 no caso contrário. 
*/
int KBD_Hit(void);

/**
* Devolve o código da tecla pressionada, é bloqueante.
* @return código da tecla pressionada
*/
int KBD_Read(void);

#endif
