#include "/home/user/Desktop/host-se1/se1/includes/TempManagement.h"
#include "/home/user/Desktop/host-se1/se1/includes/gpio.h"
#include "/home/user/Desktop/host-se1/se1/includes/led.h"

void TempManagement_Init(int pinMask){
	GPIO_config(pinMask, pinMask, 0);
}

void TempManagement_TURN(int pinMask, TURN t){
	int value = t ? pinMask : 0;
	GPIO_output(value,pinMask);
}

Alarm Alarm_Init(int pinId){
	Alarm a = {};
	a.pinMask = 1<<pinId;
	a.turn = OFF;
	LED_Init(15,0);
	return a;
}
void Alarm_ON(Alarm *a){
	a->turn = ON;
	LED_SetState(ON);
}

void Alarm_OFF(Alarm *a){
	a->turn = OFF;
	LED_SetState(OFF);
}

Cooling Cooling_Init(int pinId){
	Cooling c = {0};
	c.pinMask = 1<<pinId;
	c.turn = OFF;
	TempManagement_Init(c.pinMask);
	return c;
}

void Cooling_ON(Cooling *c){
	c->turn = ON;
	TempManagement_TURN(c->pinMask,ON);
}
void Cooling_OFF(Cooling *c){
	c->turn = OFF;
	TempManagement_TURN(c->pinMask,OFF);
}

Heating Heating_Init(int pinId){
	Heating h = {0};
	h.pinMask = 1<<pinId;
	h.turn = OFF;
	TempManagement_Init(h.pinMask);
	return h;
}

void Heating_ON(Heating *h){
	h->turn = ON;
	TempManagement_TURN(h->pinMask, ON);	
}
void Heating_OFF(Heating *h){
	h->turn = OFF;
	TempManagement_TURN(h->pinMask,OFF);
}
