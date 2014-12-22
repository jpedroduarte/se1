#include <stdio.h>
#include "keyboard.h"
#include "led.h"

void Delay(unsigned int numer);

//unsigned int layoutTest[] = {5,6,7,8,9,10,11,12,14,15,16,17,18,19,20,21};
unsigned int layoutTest[] = {1,2,3,10,4,5,6,11,7,8,9,12,13,14,15,16};

int main() {
	LED_Init(15,0);
	KBD_Init(layoutTest);
	int tecla = 0;
	while(1){
		tecla = KBD_Read();
		if(tecla != -1){
			int i;
			for(i=0; i < tecla; ++i){
				LED_SetState(1);
				Delay(500);
				LED_SetState(0);
				Delay(500);
			}
		}
	}
	return 0;
}
