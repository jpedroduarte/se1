/** @file KEYBOARD.h
*  KEYBOARD module header.
*/
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

/**
* Faz a inicia��o do sistema para permitir o acesso ao perif�rico. 
* @param layout vetor com os c�digos das 16 teclas
*/
void KBD_Init(unsigned int layout[16]);

/**
* Verifica se uma tecla foi precionada
* @return 1 se existe alguma tecla pressionada e 0 no caso contr�rio. 
*/
int KBD_Hit(void);

/**
* Devolve o c�digo da tecla pressionada, � bloqueante.
* @return c�digo da tecla pressionada
*/
int KBD_Read(void);

#endif
