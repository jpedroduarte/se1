#include "/home/user/Desktop/host-se1/se1/includes/ButtonCTRL.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/timer.h"


int main(){
	BUTTONCTRL_Init(4,0,1,2000);
	TMR0_Init(100000);
	LCD_Init();
	int res;
	while(1){
		res = BUTTONCTRL_GetButtonsEvolution();
		switch(res){
			case UPDOWNPRESSED:
				LCD_Clear();
				LCD_WriteString("UPDOWNPRESSED");

				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				LCD_WriteString("UPDOWNRELEASE");

				break;
			case UPPRESSED:
				LCD_Clear();
				LCD_WriteString("UPPRESSED");

				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				
				LCD_WriteString("UPRELEASE");

				break;
			case DOWNPRESSED:
				LCD_Clear();
				LCD_WriteString("DOWNPRESSED");

				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				LCD_WriteString("DOWNRELEASE");

				break;
			case OKPRESSED:
				LCD_Clear();
				LCD_WriteString("OKPRESSED");

				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				LCD_WriteString("OKRELEASED");

				break;
			default:
				LCD_Clear();
				LCD_WriteString("NONE");

				break;
		}
	}
	
}
