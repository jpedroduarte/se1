#include <stdio.h>
#include "/home/user/Desktop/host-se1/se1/includes/LPC2xxx.h"
#include "/home/user/Desktop/host-se1/se1/includes/LPC2106.h"
#include "/home/user/Desktop/host-se1/se1/includes/GPIO.h"

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
