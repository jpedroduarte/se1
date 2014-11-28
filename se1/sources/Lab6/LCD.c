#include <time.h>
#include "GPIO.c"
#include "LCD.h"

unsigned int data_mask = 0x00000F00;
unsigned int rs = 0x00001000;
unsigned int enable = 0x00002000;


/* Faz a iniciação do sistema para permitir o acesso ao periférico
utilizando 2 linhas com 16 colunas e comunicação a 4 bits. */
void LCD_Init(void){
	unsigned int mask = rs|enable|data_mask;
	GPIO_config( mask, mask, 0);
	
	
}

/* Escreve um carácter na posição corrente do cursor. */
void LCD_WriteChar(char ch);

/* Escreve uma string na posição corrente do cursor. */
void LCD_WriteString(char *str);

/* Posiciona o cursor na linha x e coluna y do mostrador. */
void LCD_Goto(int x, int y);

/* Limpa o visor, usando o comando disponível na API do periférico. */
void LCD_Clear(void);


void write_Nibble(int rs, unsigned int data){

	
}
