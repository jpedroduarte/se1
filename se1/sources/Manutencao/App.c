#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "/home/user/Desktop/host-se1/se1/includes/I2C.h"
#include "/home/user/Desktop/host-se1/se1/includes/LPC2xxx.h"
#include "/home/user/Desktop/host-se1/se1/includes/Menu.h"
#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "/home/user/Desktop/host-se1/se1/includes/log.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"

#include <time.h>

#define APP 0
#define MANAGER 1
#define SHOW 2

void Manutencao();
void Execute();
void Show();
void Register();
void Init();


Menu *pm;

Button *pButs;
Button *pUD;
unsigned mod;

struct tm *pDateTime;
unsigned lastHour;

struct tm dateTime = {0};

Button bUpDown[2];

int main(){
	Init();
	TempReg log[5] = {0};
	TempReg *pLog = log;
	int i=0;
	RTC_GetValue(pDateTime);
	
	while(1){
		unsigned int t = getActualTemperature();
		char* str = "00000000000";
		str = convertTemperature(str,0,0x42D8);
		LCD_WriteString(str);
	}
	//LOG
	while(i<5){
		LOG_RegistDataTemp(pLog+i,pDateTime,i);
		pDateTime->tm_hour +=1;
		i++;
	}
	i=0;
	while(i<5){
		LOG_ShowRegist(pLog+i);
		TMR0_Delay(3000);
		i++;
	}
	while(1);
	//FIM LOg
	
	RTC_GetValue(pDateTime);
	//LCD_WriteString("MODO NORMAL");
	while(1){
		// falta comunicar com o I2C de hora a hora e colocar na flash
		if(mod == APP && Button_PressedMoreThan(bUpDown,2000,2) ==1){
			mod = MANAGER;
		}
		Button_getState(pUD, 2);
		if(mod == APP && (pUD)->currentState == just_pressed){
			while(1){
				Button_getState(pUD,1);
				if((pUD)->currentState == just_released)
					break;
			}
			mod = SHOW;
		}
		if(mod == APP && (pUD+1)->currentState == just_pressed){			
			while(1){
				Button_getState(pUD+1,1);
				if((pUD+1)->currentState == just_released)
					break;
			}
			mod = SHOW;
		}
		Execute();
	}
}
void Init(){
	// ir buscar o tempo currente
	//time_t result = time(NULL); 
	//struct tm dateTime = localtime(&result);
	//printf("%s", asctime(localtime(&result)));
	
	dateTime.tm_sec = 0;
	dateTime.tm_min = 05;
	dateTime.tm_hour = 13;
	dateTime.tm_mday = 28;
	dateTime.tm_mon = 0;
	dateTime.tm_year = 2015-1900;

	pDateTime = &(dateTime);

	RTC_Init(pDateTime);
	TMR0_Init(100000);
	LCD_Init();
	I2C_Init();
	navSubMenu sbm = {
		1,
		1,
		6
	};

	Menu m = { sbm };
	pm = &m;

	Button bUp = Button_Init(0);
	Button bDown = Button_Init(1);
	Button bOk = Button_Init(4);
	bUpDown[0] = bUp;
	bUpDown[1] = bDown;
	Button allBut[3] = {
		bOk,
		bUp,
		bDown
	};
	pButs = allBut;
	pUD = bUpDown;
	mod = APP;
	lastHour =-1;
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

	RTC_GetValue(pDateTime);
	n2str(date, pDateTime->tm_mday & 0x1F, 0);
	n2str(date, pDateTime->tm_mon & 0x0F, 3);
	year2str(date, pDateTime->tm_year, 6);
	n2str(hour, pDateTime->tm_hour & 0x3F, 0);
	n2str(hour, pDateTime->tm_min & 0x3F, 3);
	
	LCD_Clear();
	LCD_On();
	LCD_WriteString("Max:"); 
	unsigned int max = I2C_Transfer(0x00, 0, (void*)0xA1, 2, I2C_FREQ); // temp max
	LCD_WriteString(""+max);
	LCD_WriteChar(' ');
	LCD_WriteString("Min:"); 
	unsigned int min = I2C_Transfer(0x00, 0, (void*)0xA2, 2, I2C_FREQ); // temp min
	LCD_WriteString(""+min);
	LCD_Goto(1,0);
	LCD_WriteString(date);
	LCD_WriteChar(' ');
	LCD_WriteString(hour);
	TMR0_Delay(5000);
	LCD_Off();
}

void Register(){
	RTC_GetValue(pDateTime);
	if(lastHour != pDateTime->tm_hour){
		lastHour = pDateTime->tm_hour;
		LCD_On();
		LCD_Clear();
		char data[1] = {0xA1};
		unsigned int TH = I2C_Transfer(0x90, 1, (void*)data, 1, I2C_FREQ); //temp actual
		data[0] = 0xA2;
		unsigned int TL = I2C_Transfer(0x90, 1, (void*)data, 1, I2C_FREQ); //temp actual

		LCD_WriteString("REGISTER");
		LCD_Off();
	}
	
}
