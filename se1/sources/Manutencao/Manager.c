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
