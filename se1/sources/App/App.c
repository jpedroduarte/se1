#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "/home/user/Desktop/host-se1/se1/includes/TempManagement.h"
#include "/home/user/Desktop/host-se1/se1/includes/Manutencao.h"

int _sbrk()
{
		return 0;
}

int main() {
	struct tm *timeptr = {0};
	timeptr->tm_sec	= 0;
	timeptr->tm_min	= 36;
	timeptr->tm_hour = 14;
	timeptr->tm_mday = 16;
	timeptr->tm_mon	= 0;
	timeptr->tm_year = 2015;
	timeptr->tm_yday = 16;
	timeptr->tm_wday = 5;
	localtime(timeptr);
	
	TMR0_Init(1000);
	RTC_Init(timeptr);
	LCD_Init();
	
	unsigned now;
	
	Button bUp =  BUTTON_Init(0);
	Button bDown =  BUTTON_Init(1);
	Button bOk =  BUTTON_Init(4);
	
	Cooling c = Cooling_Init(5);
	Heating h = Heating_Init(6);
	
	Alarm a = Alarm_Init(15);
	char *arr[sizeof(struct tm)];
	
	const struct tm *dT;
	RTC_GetValue(timeptr);
	char *time = asctime(timeptr);
	LCD_WriteString("00-00");
	LCD_Goto(0,1);
	char* hour = "00";
	char* min = "00";
	int i = 0, col=0;
	while(1){
	/*	if(BUTTON_getState(bUp)){
			i++;
			if(i ==24)
				i=0;
			n2str(hour,i,col);
			LCD_Goto(0,col);
			LCD_WriteString(hour);
			LCD_Goto(0,col+1);
			TMR0_Delay(1000);
		}
		if(BUTTON_getState(bDown)){
			i--;
			if(i <0)
				i=23;
			n2str(hour,i,0);
			LCD_Goto(0,col);
			LCD_WriteString(hour);
			LCD_Goto(0,col+1);
			TMR0_Delay(1000);
		}
		if(BUTTON_getState(bOk)){
			if(col ==3){
				LCD_Goto(1,0);
				LCD_WriteString("Alterada");
				TMR0_Delay(2000);
				break;
			}
			col +=3;
			LCD_Goto(0,col+1);
			TMR0_Delay(1000);
		}
		* */
		
		LCD_Clear();
		int i=0;
		while(i < 26){
			LCD_WriteChar(time[i]);
			if(i==15)
				LCD_Goto(1,0);
				i++;
			TMR0_Delay(100);
		}
		TMR0_Delay(5000);
		LCD_Clear();
		
		/*if(BUTTON_getState(bUp)){
			Cooling_ON(c);
			TMR0_Delay(2000);
			if(Menu_IsChangeable(m,UP)){
				m = Menu_changeSubMenu(m,UP);
				LCD_Clear();
				LCD_WriteString(subMenuL1[m.currSubMenu-1]);
				LCD_Goto(1,0);
				LCD_WriteString(subMenuL2[m.currSubMenu-1]);
			}
			Cooling_OFF(c);
		}
		if(BUTTON_getState(bDown)){
			Heating_ON(h);
			TMR0_Delay(2000);
			if(Menu_IsChangeable(m,DOWN)){
					m = Menu_changeSubMenu(m,DOWN);
					LCD_Clear();
					LCD_WriteString(subMenuL1[m.currSubMenu-1]);
					LCD_Goto(1,0);
					LCD_WriteString(subMenuL2[m.currSubMenu-1]);
			}
			Heating_OFF(h);
		}
		
		if(BUTTON_getState(bOk)){
			Alarm_ON(a);
			TMR0_Delay(3000);
			Alarm_OFF(a);
		}
		
		TMR0_Delay(1000);
		*/
	}

}
