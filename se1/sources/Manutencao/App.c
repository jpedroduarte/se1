#include "/home/user/Desktop/host-se1/se1/includes/ButtonCTRL.h"
#include "/home/user/Desktop/host-se1/se1/includes/I2C.h"
#include "/home/user/Desktop/host-se1/se1/includes/LPC2xxx.h"
#include "/home/user/Desktop/host-se1/se1/includes/Menu.h"
#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "/home/user/Desktop/host-se1/se1/includes/log.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"
#include "/home/user/Desktop/host-se1/se1/includes/TempManagement.h"


#include <time.h>

#define APP 0
#define MANAGER 1
#define SHOW 2

void Manutencao();
void Execute();
void Show();
void Register();
void Init();
		
Menu m;

Menu *pm;

//Button *pButs;
//Button *pUD;
unsigned mod;

struct tm *pDateTime;
unsigned lastHour;

struct tm dateTime = {0};

//Button bUpDown[2];
//Button allBut[3];

Menu m;

Cooling c = {0};
Heating h = {0};
Alarm a = {0};

unsigned tmax ,tmin;
unsigned int timeCheck, timeSave;
RegsLog tempRegistLog = {0};

int main(){
	Init();
	
	int i=0;
	RTC_GetValue(pDateTime);
	
	/*while(i<5){
		t = getActualTemperature();
		LOG_RegistDataTemp(pLog+i,pDateTime,t);
		pDateTime->tm_hour +=1;
		i++;
	}
	i=0;
	while(i<5){
		LOG_ShowRegist(pLog+i);
		TMR0_Delay(3000);
		i++;
	}

	//FIM LOg*/
	unsigned t, now;
	tmax= THERM_Temp2short(35);
	tmin =THERM_Temp2short(30);
	RTC_GetValue(pDateTime);
	int buttons;
	while(1){
		buttons = BUTTONCTRL_GetButtonsEvolution();
		//MODO MANUTENCAO
		if(mod == APP && (buttons == UPDOWNPRESSED)){
			LCD_Clear();
			LCD_WriteString("MANUTENCAO");
			while(!BUTTONCTRL_RELEASE());
			mod = MANAGER;
		}
		//MOSTRAR TEMP ACT
		if(mod == APP && (buttons == UPPRESSED || buttons == DOWNPRESSED)){
			LCD_Clear();
			LCD_WriteString("SHOW");
			while(!BUTTONCTRL_RELEASE());
		}
		
		//t = THERM_getActualTemperature();
		//if(THERM_compareTemperature((short)t,tmax) > 0 ){
			//Cooling_ON(&c);
			//now = TMR0_GetValue();
			//while(THERM_compareTemperature((short)t,tmax) > 0 ){
				//if(TicksToMS(TMR0_Elapsed(now)) >= 60000){
					//Alarm_ON(&a);
					//while(1){
						//Button_getState(pButs, 1);
						//if(pButs->currentState == just_pressed){
				
							//while(1){
								//Button_getState(pButs,1);
								//if((pButs)->currentState == just_released)
									//break;
							//}
							//break;
						//}
					//}
					//Alarm_OFF(&a);
					//break;
				//}
				//t = THERM_getActualTemperature();
			//}
			//Cooling_OFF(&c);
		//}
		//if(THERM_compareTemperature((short)t,tmin) <0){
			//Heating_ON(&h);
			//now = TMR0_GetValue();
			//while(THERM_compareTemperature((short)t,tmin) <0){
				
				//if(TicksToMS(TMR0_Elapsed(now)) >= 60000){
					//Alarm_ON(&a);
					//while(1){
						//Button_getState(pButs, 1);
						//if(pButs->currentState == just_pressed){
							//while(1){
								//Button_getState(pButs,1);
								//if((pButs)->currentState == just_released)
									//break;
							//}
							//break;
						//}
					//}
					//Alarm_OFF(&a);
					//break;
				//}
				//t = THERM_getActualTemperature();
			//}
			//Heating_OFF(&h);
		//}
		
		/*
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
		*/
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
	unsigned int t = THERM_getActualTemperature();
	LOG_RegistDataTemp(&(pRegLog->temps[0]),pDateTime,t);
	t = THERM_getActualTemperature();
	LOG_RegistDataTemp(&(pRegLog->temps[1]),pDateTime,t);
	
	LOG_Init(pRegLog);
	
	c = Cooling_Init(5);
	h = Heating_Init(6);
	
	a = Alarm_Init(15);
	
	m.sbm.curr = 1;
	m.sbm.first = 1;
	m.sbm.last = 6;
	pm = &m;

	//OK pin 4, UP pin 0, DOWN pin 1, Time to Pressed UP/DOWN 2000ms(2s)
	BUTTONCTRL_Init(4,0,1,2000);
	
	mod = APP;
	pRegLog = &tempRegistLog;
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
			Register();
			mod = APP;
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
	int buttons;
	Manager_Print(pm);
	while(1){
		buttons = BUTTONCTRL_GetButtonsEvolution();
		//MODO MANUTENCAO
		if(buttons == OKPRESSED)){
			while(!BUTTONCTRL_RELEASE());
			if(Manager_Entry(pm, pButs,3))
				break;
		}		
		
		else if(buttons == UPPRESSED)){
			while(!BUTTONCTRL_RELEASE());
			
		}
		
		else if(buttons == DOWNPRESSED)){
			while(!BUTTONCTRL_RELEASE());
			
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
	}*/
}

void Show(){
	char *hour = "00:00";
	char *date = "00-00-0000";
	int tactual = THERM_getActualTemperature();
	
	RTC_GetValue(pDateTime);
	n2str(date, pDateTime->tm_mday & 0x1F, 0);
	n2str(date, pDateTime->tm_mon & 0x0F, 3);
	year2str(date, pDateTime->tm_year, 6);
	n2str(hour, pDateTime->tm_hour & 0x3F, 0);
	n2str(hour, pDateTime->tm_min & 0x3F, 3);
	
	LCD_Clear();
	LCD_On();
	LCD_WriteString(""+tmin);
	//LCD_WriteChar('   ');
	LCD_WriteString(""+tactual);
	//LCD_WriteChar('   ');
	LCD_WriteString(""+tmax);	
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
		short temp = THERM_Temp2short(THERM_getActualTemperature());
		LOG_RegistDataTemp(&(pRegLog->temps[1]), pDateTime, temp); 
		LCD_WriteString("REGISTER");
		LCD_Off();
	}
	
}

int Check_Limits(int state){ //NOTA: nao e bem isto, preciso melhorar
	unsigned t;
	t = THERM_getActualTemperature();
	if(state){ // quando ja esta em cooling ou heating 
		if(THERM_compareTemperature((short)t,tmax)>0 || THERM_compareTemperature((short)t,tmin)<0){
			if(TicksToMS(TMR0_Elapsed(timeCheck)) >= 60000){
				Alarm_ON(&a); // para desligar o alarme e ver no main se foi carregado ok
			}
		}
		return 0;
	}
	else{ //quando e activado a 1ªvez
		if(THERM_compareTemperature((short)t,tmax)>0){
			Cooling_ON(&c);
			timeCheck = TMR0_GetValue();
			return 1;
		}
		if(THERM_compareTemperature((short)t,tmin)<0){
			Heating_ON(&h);
			timeCheck = TMR0_GetValue();
			return 1;
		}
		Cooling_OFF(&c);
		Heating_OFF(&h);
		return 0;
	}
}
