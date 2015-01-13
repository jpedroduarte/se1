#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO.h"

typedef struct Button{
	int pinMask;
} Button;

Button BUTTON_Init(int pinId);

int BUTTON_getState(Button b);

#endif
