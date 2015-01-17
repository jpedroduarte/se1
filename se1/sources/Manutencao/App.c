#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "Menu.h"

int main(){
	TMR0_Init(1000);
	LCD_Init();
	navSubMenu sbm = {
		1,
		1,
		6
	};
	Button bUp =  BUTTON_Init(0);
	Button bDown =  BUTTON_Init(1);
	Button bOk =  BUTTON_Init(4);
	
	Menu m = {sbm};
	Manager_Print(&m);

	while(1){
		if(BUTTON_getState(bUp)){
			MENU_Navigation(&m,UP);
			Manager_Print(&m);
			TMR0_Delay(1000);
		}
		if(BUTTON_getState(bDown)){
			MENU_Navigation(&m,DOWN);
			Manager_Print(&m);
			TMR0_Delay(1000);
		} 
	}	
}
