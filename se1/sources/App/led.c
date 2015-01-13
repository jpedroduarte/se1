#include "led.h"
#include "GPIO.h"

static unsigned int dir_mask;

/* 
 * pinID -> numero do pin do led
 * state-> ON = 0 OFF!=0
 * */
void LED_Init(int pinId, int state){
	dir_mask = 1<<pinId;
	unsigned int value = state ? dir_mask : 0;
	GPIO_config( dir_mask, dir_mask , value );
}

int LED_GetState(void){
	return GPIO_input() & dir_mask;
}

void LED_SetState(int state){
	unsigned int value = state ? dir_mask : 0;
	GPIO_output(value, dir_mask);
}

