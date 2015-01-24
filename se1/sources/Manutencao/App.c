#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "Menu.h"
#include "/home/user/Desktop/host-se1/se1/sources/Lab7/LPC2xxx.h"
#include <time.h>

#define APP 0
#define MANAGER 1
#define SHOW 2

void Manutencao();
void Execute();
void Show();
void Register();


Menu *pm;

Button *pButs;
Button *pUD;
unsigned mod;

struct tm *dateTime;
unsigned lastHour;

int main(){
	dateTime = {0};
	dateTime->tm_sec = 0;
	dateTime->tm_min = 20;
	dateTime->tm_hour = 12;
	dateTime->tm_mday = 23;
	dateTime->tm_mon = 1;
	dateTime->tm_year = 2015;
	
	RTC_Init(dateTime);
	
	TMR0_Init(100000);
	LCD_Init();
	
	navSubMenu sbm = {
		1,
		1,
		6
	};
	
	Menu m = {sbm};
	pm = &m;
	
	Button bUp =  Button_Init(0);
	Button bDown =  Button_Init(1);
	Button bOk =  Button_Init(4);
	Button bUpDown[2] = { bUp, bDown};
	Button allBut[3] = {
		bOk,
		bUp,
		bDown		
	};		
	pButs = allBut;
	pUD = bUpDown;
	mod = APP;
	LCD_WriteString("MODO NORMAL");
	while(1){
		
		if(mod == APP && Button_PressedMoreThan(bUpDown,2000,2) ==1){
			mod = MANAGER;
		}
		Button_getState(pUD, 2);
		if(mod == APP && (pUD)->currentState == just_pressed){
			Button_getState(pUD,1);
			if((pUD)->currentState == just_released)
				break;
			mod = SHOW;
		}
		if(mod == APP && (pUD+1)->currentState == just_pressed){
			Button_getState(pUD+1,1);
			if((pUD+1)->currentState == just_released)
				break;
			mod = SHOW;
		}
		Execute();
	}
}

void Execute(){
	switch(mod){
		case MANAGER:
			Manutencao();
			mod = APP;
			break;
		case SHOW:
			Show();
			mod = APP;
			break;
		default:
			mod = APP;
			Register();
			break;
	}
	
}
void Manutencao(){
	LCD_Clear();
	LCD_On();
	pm->sbm.curr = 1;
	LCD_WriteString("Modo de");
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
			if(Manager_Entry(pm, pButs,3))
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
}

void Show(){
	char *hour = "00:00";
	char *date = "00-00-0000";
	LCD_Clear();
	LCD_On();
	LCD_WriteString("Max:"); 
	LCD_WriteString("20");// temp max
	LCD_WriteChar(' ');
	LCD_WriteString("Min:"); 
	LCD_WriteString("10");// temp min
	LCD_Goto(1,0);
	LCD_WriteString(date);
	LCD_WriteChar(' ');
	LCD_WriteString(hour);
	TMR0_Delay(5000);
	LCD_Off();
}

void Register(){
	RTC_GetValue(dateTime);
	if(lastHour != dateTime->tm_hour){
		lastHour = dateTime->tm_hour;
		LCD_On();
		LCD_Clear();
		LCD_WriteString("REGISTER");
		LCD_Off();
	
	}
	
}
