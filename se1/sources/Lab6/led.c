/** @file LED.c
*  LED module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/led.h"
#include "/home/user/Desktop/host-se1/se1/includes/GPIO.h"


static unsigned int dir_mask;

/**
* Faz a iniciação do sistema para permitir a manipulação do estado LED
* @param pinID pino a que o led se encontra ligado
* @param state ON != 0 OFF == 0
*/
void LED_Init(int pinId, int state){
	dir_mask = 1<<pinId;
	unsigned int value = state ? dir_mask : 0;
	GPIO_config( dir_mask, dir_mask , value );
}

/**
* Devolve o estado do led
* @return 0 se o LED está apagado e um valor diferente de zero no caso
contrário
*/
int LED_GetState(void){
	return GPIO_input() & dir_mask;
}

/**
* Altera o estado do led
* @param state apaga o LED se state = 0 ou acende o LED no caso contrário.
*/
void LED_SetState(int state){
	unsigned int value = state ? dir_mask : 0;
	GPIO_output(value, dir_mask);
}

