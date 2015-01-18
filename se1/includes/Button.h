/** @file Button.h
*  Button module header.
*/
#ifndef BUTTON_H
#define BUTTON_H

#include "/home/user/Desktop/host-se1/se1/includes/gpio.h"
/**
 * Estrutura que define um botao
 */
typedef struct Button{
	int pinMask;
	enum state currentState;
} Button;

/**
 * Cria um novo botao atribuido a um pin
 * @param pinId Indica o pin a qual o botao esta ligado
 * @return retorna um novo botao
 */
Button Button_Init(int pinId);

/**
 * Devolve o valor que se encontra no pin daquele botao
 * @param b Butao da qual se pretende saber o estado do porto
 * @return retorna 0 ou 1
 */
int Button_getPortState(Button b);

/**
 * Avalia e altera o estado do botao
 * @param b Butao da qual se pretende avaliar o estado
 */
void Button_setState(Button b);

#endif
