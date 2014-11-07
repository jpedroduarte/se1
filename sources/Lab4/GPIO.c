#include <stdio.h>
#include "LPC2xxx.h"
#include "LPC2106.h"

void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue);
void GPIO_output(unsigned int value);
unsigned int GPIO_input(unsigned int mask); 
