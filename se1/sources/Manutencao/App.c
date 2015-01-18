#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "/home/user/Desktop/host-se1/se1/includes/LCD.h"
#include "/home/user/Desktop/host-se1/se1/includes/RTC.h"
#include "/home/user/Desktop/host-se1/se1/includes/Manager.h"
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

void showInfo(){
	char *hour = "00:00";
	char *date = "00-00-0000";
	
	struct tm *dateTime = {0};
	RTC_GetValue(dateTime);
	n2str(date, dateTime->tm_mday & 0x1F, 0);
	n2str(date, dateTime->tm_mon & 0x0F, 3);
	putYear(date, dateTime->tm_year, 6);
	n2str(hour, dateTime->tm_hour & 0x3F, 0);
	n2str(hour, dateTime->tm_min & 0x3F, 3);
	
	Se
	
	LCD_On();
	LCD_WriteString("Max:"); 
	LCD_WriteString();// temp max
	LCD_WriteChar(' ');
	LCD_WriteString("Min:"); 
	LCD_WriteString();// temp min
	LCD_Goto(1,0);
	LCD_WriteString(date);
	LCD_WriteChar(' ');
	LCD_WriteString(hour);
	TMR0_Delay(5);
	LCD_Off();
}

void saveData(){
	Fla
}
