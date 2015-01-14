#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Button.h"
#include "/home/user/Desktop/host-se1/se1/includes/menu.h"

const char *subMenuL1[] = {	"1 - Definir",
							"2 - Definir",
							"3 - Relogio",
							"4 - Calendario",
							"5 - Visualizar",
							"6 - Sair da"};

const char *subMenuL2[] = {	"TMax = 000 graus",
							"TMin = 000 graus",
							"        00-00-00",
							"      00-00-0000",
							"    Temperaturas",
							"      Manutencao"};



int main() {
	TMR0_Init(1000);
	LCD_Init();
	LED_Init(15,0);
	unsigned now;
	Button bUp =  BUTTON_Init(0);
	Button bDown =  BUTTON_Init(1);
	
	Menu m = Menu_Create(6);
	LCD_WriteString("MODO DE");
	LCD_Goto(1,6);
	LCD_WriteString("Manutencao");
	
	now = TMR0_GetValue();
	while(TMR0_Elapsed(now) < 3000);
	
	LCD_Clear();
	
	LCD_WriteString(subMenuL1[m.currSubMenu-1]);
	LCD_Goto(1,0);
	LCD_WriteString(subMenuL2[m.currSubMenu-1]);
	
	while(1){
		
		if(BUTTON_getState(bUp)){
			
			if(Menu_IsChangeable(m,UP)){
				m = Menu_changeSubMenu(m,UP);
				LCD_Clear();
				LCD_WriteString(subMenuL1[m.currSubMenu-1]);
				LCD_Goto(1,0);
				LCD_WriteString(subMenuL2[m.currSubMenu-1]);
			}
		}
		if(BUTTON_getState(bDown)){
			if(Menu_IsChangeable(m,DOWN)){
					m = Menu_changeSubMenu(m,DOWN);
					LCD_Clear();
					LCD_WriteString(subMenuL1[m.currSubMenu-1]);
					LCD_Goto(1,0);
					LCD_WriteString(subMenuL2[m.currSubMenu-1]);
			}
		}
		now = TMR0_GetValue();
		while(TMR0_Elapsed(now) < 1000);
	}

}
