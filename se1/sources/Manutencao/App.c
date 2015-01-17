
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
	Menu *pm = &m;
	
	LCD_WriteString("MODO DE");
	LCD_Goto(1,6);
	LCD_WriteString("Manutencao");
	TMR0_Delay(3000);

	Manager_Print(pm);

	while(1){
		if(BUTTON_getState(bOk)){
			if(Manager_Entry(pm))
				break;
		}
		
		if(BUTTON_getState(bUp)){
			MENU_Navigation(pm,UP);
			Manager_Print(pm);
			TMR0_Delay(1000);
		}
		if(BUTTON_getState(bDown)){
			MENU_Navigation(pm,DOWN);
			Manager_Print(pm);
			TMR0_Delay(1000);
		} 
	}
	LCD_Clear();
	LCD_WriteString("MODO NORMAL");
	while(1);	
}
