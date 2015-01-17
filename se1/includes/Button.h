#ifndef BUTTON_H
#define BUTTON_H

#include "/home/user/Desktop/host-se1/se1/includes/gpio.h"

typedef struct Button{
	int pinMask;
} Button;

Button BUTTON_Init(int pinId);

int BUTTON_getState(Button b);

#endif
