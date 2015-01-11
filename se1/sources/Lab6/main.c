#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lcd.h"
#include "Timer.h"
#include "RTC.h"

void n2str(char * str, int n, int p);
void putYear(char * str, int n, int p);
void Alarm();

int main() {
	struct tm *dateTime = {0};
	dateTime->tm_sec	= 0;
	dateTime->tm_min	= 30;
	dateTime->tm_hour = 17;
	dateTime->tm_mday = 11;
	dateTime->tm_mon	= 1;
	dateTime->tm_year = 2015;
	RTC_Init(dateTime);
	TMR0_Init(1000);
	LCD_Init();
	LED_Init(15,0);
	char *hour = "00H-00M-00S";
	char *date = "00D-00M-0000A";
	unsigned now;
	while(1){
		RTC_GetValue(dateTime);
		
		
		n2str(date, dateTime->tm_mday & 0x1F, 0);
		n2str(date, dateTime->tm_mon & 0x0F, 4);
		putYear(date, dateTime->tm_year, 8);
		LCD_WriteString(date);
		LCD_Goto(1,0);
		
		n2str(hour, dateTime->tm_hour & 0x3F, 0);
		n2str(hour, dateTime->tm_min & 0x3F, 4);
		n2str(hour, dateTime->tm_sec & 0x3F, 8);
		LCD_WriteString(hour);
		
		now = TMR0_GetValue();
		while(TMR0_Elapsed(now) < 700);
		LCD_Goto(0,0);
	}

	
	return 0;
}

void n2str(char * str, int n, int p){
	*(str + p) = '0'+(n/10);
	*(str + p + 1) = ('0' +(n%10));
}

void putYear(char * str, int n, int p){
	*(str + p) = '0'+(n/1000);
	*(str + p +1) = '0'+((n%1000)/100);
	*(str + p + 2) = '0'+(((n%1000)%100)/10);
	*(str + p + 3) = ('0' +(n%10));
	
}


