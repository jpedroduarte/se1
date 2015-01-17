/** @file GPIO.h
*  GPIO module header.
*/

#ifndef GPIO_H
#define GPIO_H

/**
 * Configura os pinos do GPIO 
 * @param dir Indica a direção do pin (Input/Output)
 * @param mask Indica os pinos que se pretende afectar
 * @param initvalue Indica o valor inicial do pin
*/
void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue);

/**
* Configura o valor dos pinos de output
* @param value Indica o valor de output do pin
* @param mask Indica os pinos que se pretende afectar com o value
*/
void GPIO_output(unsigned int value, unsigned int mask);

/**
* Retorna o valor dos pinos de Input
* @return valor dos pin de Input
*/
unsigned int GPIO_input();

#endif
