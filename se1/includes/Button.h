/** @file Button.h
*  Button module header.
*/
#ifndef BUTTON_H
#define BUTTON_H

#include "/home/user/Desktop/host-se1/se1/includes/gpio.h"

/**
 * Define os tipos de estados que um botao pode ter
 */
typedef enum states {just_pressed, pressed, just_released, released} States;

/**
 * Estrutura que define um botao
 */
typedef struct Button{
	int pinMask;
	States currentState;
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
int Button_getPortState(int maskButtons);

/**
 * Avalia e altera o estado do botao
 * @param b Botao da qual se pretende avaliar o estado
 */
void Button_setState(Button *b);

/**
 * Devolve 1 se o botao foi pressionado
 * @param b Arrray com os Botoes que se pretende verificar se foram pressionados
 * @param s Botao da qual se pretende avaliar o estado
 * @return retorna 0 ou 1
 */
void Button_getState(Button *b, int nBut);

/**
 * Devolve 1 se o botao foi pressionado
 * @param b Botao da qual se pretende avaliar o estado
 * @param t tempo para o botao estar pressionado
 * @return retorna 0 ou 1
 */
int Button_PressedMoreThan(Button b[], int t, int nBut);

#endif
