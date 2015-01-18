#include <stdio.h>
#include <stdlib.h>

#include "Manager.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"

void Manager_Print(Menu *m){
	int curr = MENU_getCurr(m) -1;
	LCD_Clear();
	LCD_WriteString(Manager_getStringMenu(curr,L0));
	LCD_Goto(1,0);
	LCD_WriteString(Manager_getStringMenu(curr,L1));
}

char* Manager_getStringMenu(int curr, int line){
	ManagerInfo* ptr = Manager_getMenu(curr);
	return ptr->lines[line];
}

ManagerInfo* Manager_getMenu(int curr){
	return ((ManagerInfo*)pMenus)+curr;
}

int Manager_Entry(Menu *m){
	int curr = MENU_getCurr(m)-1;
	ManagerInfo* ptr = Manager_getMenu(curr);
	EntryMode e = ptr->enter;
	e.on = 1;
	Manager_Enter(e);
	if(e.mType != EXIT){
		Manager_Print(m);
		return 0; //CONTINUE IN MANAGER
	}
	return 1; //EXIT MANAGER
}

void Manager_Enter(EntryMode e){
	ManType mT = e.mType;
	int x = 1;
	int y = 6;
	//int x = Manager_EntryX(e);
	//	int y = Manager_EntryY(e);
	switch(mT){
		case SET:
			LCD_Goto(x,y);
			TMR0_Delay(5000);
			break;
		case LOG:
			LCD_Clear();
			LCD_WriteString("LOG TEMP******");
			TMR0_Delay(5000);
			
			break;
		case EXIT:
			LCD_Clear();
			LCD_WriteString("EXIT");
			TMR0_Delay(5000);
			break;
		default:
			break;
	}
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
