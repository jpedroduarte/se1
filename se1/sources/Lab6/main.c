#include <stdio.h>
#include "lcd.h"
#include "Timer.h"

int main() {
	TMR0_Init(1000);
	LCD_Init();
	LCD_Clear();
	char *str = "OLA SUSANA";
	LCD_WriteString(str);
	return 0;
}
