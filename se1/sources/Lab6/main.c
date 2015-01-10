#include <stdio.h>
#include "lcd.h"
#include "Timer.h"

int main() {
	TMR0_Init(1000);
	LCD_Init();
	LCD_Clear();
	char *str = "ESTAMOS EM SE1", *str2 = "09-01-2015";
	LCD_Goto(0,1);
	LCD_WriteString(str);
	LCD_Goto(1,0);
	LCD_WriteString(str2);
	return 0;
}
