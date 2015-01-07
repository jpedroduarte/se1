#include <stdio.h>
#include "lcd.h"

int main() {
	LCD_Init();
	char *str = "OLA SUSANA";
	LCD_WriteString(str);
	return 0;
}
