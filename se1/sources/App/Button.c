#include "Button.h"

Button BUTTON_Init(int pinId){
	Button b = {0};
	b.pinMask = 1<<pinId;
	GPIO_config( 0, b.pinMask , 0 );
	return b;
}

int BUTTON_getState(Button b){
	return GPIO_input() & b.pinMask;
}
