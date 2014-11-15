#include <stdio.h>
#include "LPC2xxx.h"
#include "LPC2106.h"
#include "GPIO.h"

void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue){	
	dir &= mask;
	GPIO.IODIR &= ~mask;
	GPIO.IODIR |= dir; 
	GPIO.IOPIN= ((GPIO.IOPIN & ~mask ) | initvalue );
}

void GPIO_output(unsigned int value, unsigned int mask){
	GPIO.IOPIN= (GPIO.IOPIN & ~mask) | value;
}

unsigned int GPIO_input(){
	return GPIO.IOPIN;
}
