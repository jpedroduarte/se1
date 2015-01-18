
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
	
	Button bUp =  Button_Init(0);
	Button bDown =  Button_Init(1);
	Button bOk =  Button_Init(4);
	
	Menu m = {sbm};
	Menu *pm = &m;
	Button bUpDown[2] ={ bUp, bDown};
	while(Button_PressedMoreThan(bUpDown,2000,2) !=1);
	
	Button allBut[3] = {
		bOk,
		bUp,
		bDown
		
	};
	
	Button *pButs = allBut;
	
	LCD_WriteString("MODO DE");
	LCD_Goto(1,6);
	LCD_WriteString("Manutencao");
	TMR0_Delay(3000);

	
	while(1){
		Button_getState(pButs, 3);
		if(pButs->currentState == released &&
			(pButs+1)->currentState == released &&
			(pButs+2)->currentState == released)
			break;
	}
	
	Manager_Print(pm);
	while(1){
		Button_getState(pButs, 3);
		if(pButs->currentState == just_pressed){
			
			while(1){
				Button_getState(pButs,1);
				if((pButs)->currentState == just_released)
					break;
			}
			if(Manager_Entry(pm))
				break;
		}
		
		if((pButs+1)->currentState == just_pressed){
			while(1){
				Button_getState(pButs+1,1);
				if((pButs+1)->currentState == just_released)
					break;
			}
			MENU_Navigation(pm,UP);
			Manager_Print(pm);
			TMR0_Delay(1000);
		}
		if((pButs+2)->currentState == just_pressed){
			while(1){
				Button_getState(pButs+2,1);
				if((pButs+2)->currentState == just_released)
					break;
			}
			MENU_Navigation(pm,DOWN);
			Manager_Print(pm);
			TMR0_Delay(1000);
		} 
	}
	LCD_Clear();
	LCD_WriteString("MODO NORMAL");
	while(1);	
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
