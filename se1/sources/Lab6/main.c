#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void n2str(char * str, int n, int p);
void putYear(char * str, int n, int p);

int main() {
	///*
	struct tm *dateTime = {0};
	dateTime->tm_sec	= 0;
	dateTime->tm_min	= 49;
	dateTime->tm_hour = 15;
	dateTime->tm_mday = 13;
	dateTime->tm_mon	= 1;
	dateTime->tm_year = 2015;
	
	RTC_Init(dateTime);
	TMR0_Init(1000);
	LCD_Init();
	LED_Init(15,0);
	
	char *hour = "00-00-00";
	char *date = "00-00-0000";
	unsigned now;
	int bool = 1;
	while(1){
		RTC_GetValue(dateTime);

		n2str(date, dateTime->tm_mday & 0x1F, 0);
		n2str(date, dateTime->tm_mon & 0x0F, 3);
		putYear(date, dateTime->tm_year, 6);
		
	    n2str(hour, dateTime->tm_hour & 0x3F, 0);
		n2str(hour, dateTime->tm_min & 0x3F, 3);
		n2str(hour, dateTime->tm_sec & 0x3F, 6);
		
		if(bool){
			LCD_Goto(0,0);
			LCD_WriteString("TIME:");
		}
		
		LCD_Goto(0,8);
		LCD_WriteString(hour);
		
		if(bool){
			LCD_Goto(1,0);
			LCD_WriteString("DATE:");
			bool =0;
		}
		
		LCD_Goto(1,6);
		LCD_WriteString(date);
		
		TMR0_Delay(600);
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


