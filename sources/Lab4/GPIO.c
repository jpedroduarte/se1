#include <stdio.h>
#include "LPC2xxx.h"
#include "LPC2106.h"

GPIO_DSC gpio;

void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue){
		if(dir)//Set pins in mask to GPIO function Output 
		{
			gpio.IODIR |= mask; 
			gpio.IOPIN= ((gpio.IOPIN & ~mask ) |initvalue);
			
		}else //Set pins in mask to GPIO function Input
		{
			gpio.IODIR &= ~mask;
		}
		
}

void GPIO_output(unsigned int value, int mask){
	gpio.IOPIN= (gpio.IOPIN & ~mask) | value;
}

unsigned int GPIO_input(unsigned int mask){
	return gpio.IOPIN & mask;
}
