#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lcd.h"
#include "Timer.h"
#include "RTC.h"

void n2str(char * str, int n, int p);
void Alarm();

int main() {
	struct tm *dateTime = {0};
	dateTime->tm_sec	= 0;
	dateTime->tm_min	= 30;
	dateTime->tm_hour = 17;
	dateTime->tm_mday = 10;
	dateTime->tm_mon	= 1;
	dateTime->tm_year = 2015;
	RTC_Init(dateTime);
	TMR0_Init(1000);
	LCD_Init();
	LED_Init(15,0);
	LCD_WriteString("HORAS:");
	char *str = "00H-00M-00S";
	unsigned now;
	char *ALM = "          ALARME";
	int i=10;
	now = TMR0_GetValue();
    while(TMR0_Elapsed(now) < 1000);
	while(i >=0){
		LCD_Goto(1,0);
		//RTC_GetValue(dateTime);
		//n2str(str, dateTime->tm_hour & 0x3F, 0);
		//n2str(str, dateTime->tm_min & 0x3F, 4);
		//n2str(str, dateTime->tm_sec & 0x3F, 8);
		LCD_WriteString(ALM+i);
		now = TMR0_GetValue();
		while(TMR0_Elapsed(now) < 1000);
		i--;
	}

	
	return 0;
}

void n2str(char * str, int n, int p){
	*(str + p) = '0'+(n/10);
	*(str + p + 1) = ('0' +(n%10));
}

void Alarm(){
char *ALM = "          ALARME";
	int i=10;
	now = TMR0_GetValue();
    while(TMR0_Elapsed(now) < 1000);
	while(i >=0){
		LCD_Goto(1,0);
		//RTC_GetValue(dateTime);
		//n2str(str, dateTime->tm_hour & 0x3F, 0);
		//n2str(str, dateTime->tm_min & 0x3F, 4);
		//n2str(str, dateTime->tm_sec & 0x3F, 8);
		LCD_WriteString(ALM+i);
		now = TMR0_GetValue();
		while(TMR0_Elapsed(now) < 1000);
		
		i--;
	}	
	
}

