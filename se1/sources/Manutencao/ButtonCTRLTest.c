#include "/home/user/Desktop/host-se1/se1/includes/ButtonCTRL.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/timer.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"
#include "/home/user/Desktop/host-se1/se1/includes/i2c.h"

int main(){
	BUTTONCTRL_Init(4,0,1,2000);
	TMR0_Init(100000);
	I2C_Init();
	LCD_Init();
	LCD_Off();
	int res, temp;
	char *str = "0000,0000.C";
	while(1){
		res = BUTTONCTRL_GetButtonsEvolution();
		
		
		switch(res){
			case UPDOWNPRESSED:
				LCD_On();
				LCD_Clear();
				LCD_WriteString("MANUTENCAO");
				
				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				LCD_WriteString("SAIR DA MANUTENCAO");
				break;
			case UPPRESSED:
				temp = THERM_getActualTemperature();
				THERM_getLogTemperature(str,0,temp);
				LCD_On();
				LCD_Clear();
				LCD_WriteString(str);
				TMR0_Delay(5000);
				LCD_Off();
				while(!BUTTONCTRL_RELEASE());
				break;
			case DOWNPRESSED:
				temp = THERM_getActualTemperature();
				THERM_getLogTemperature(str,0,temp);
				LCD_On();
				LCD_Clear();
				LCD_WriteString(str);
				TMR0_Delay(5000);
				LCD_Off();
				while(!BUTTONCTRL_RELEASE());
				break;
			case OKPRESSED:
			/*
				LCD_Clear();
				LCD_WriteString("OKPRESSED");

				LCD_Goto(1,0);
				while(!BUTTONCTRL_RELEASE());
				LCD_WriteString("OKRELEASED");

				break;*/
			default:
				LCD_Off();
				break;
		}
	}
	
}
