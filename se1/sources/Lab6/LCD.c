#include <time.h>
#include "GPIO.h"
#include "LCD.h"

unsigned int data_mask = 0x00000F00;
unsigned int rs_mask = 0x00001000;
unsigned int enable_mask = 0x00002000;


/* Faz a iniciação do sistema para permitir o acesso ao periférico
utilizando 2 linhas com 16 colunas e comunicação a 4 bits. */
void LCD_Init(void){
	unsigned int mask = rs_mask|enable_mask|data_mask;
	GPIO_config( mask, mask, 0);
	//Por um time.sleep(60);
	write_Nibble(0,0x03);
	//Por um time.sleep(5);
	write_Nibble(0,0x03);
	writeNibble(0,0x3);
	writeNibble(0,0x2);

	writeByte(0,0x28);
	writeByte(0,0x08);
	writeByte(0,0x01);
	writeByte(0,0x06);
	writeByte(0,0x0D);
	
}

/* Escreve um carácter na posição corrente do cursor. */
void LCD_WriteChar(char ch){
		write_Byte(1,ch);
}

/* Escreve uma string na posição corrente do cursor. */
void LCD_WriteString(char *str){
	while(str){
		write_Byte(1,*str);
		++str;
	}
}

/* Posiciona o cursor na linha x e coluna y do mostrador. */
void LCD_Goto(int x, int y){
		write_Byte(0,(y==0)? 0x80+x:0xC0+x );
		//time.sleep(2);
}

/* Limpa o visor, usando o comando disponível na API do periférico. */
void LCD_Clear(void){
	write_Nibble(0,0x01);
	//time.sleep(2);
}

void write_Byte(int rs, int c){
		write_Nibble(rs,c >> 4);
		write_Nibble(rs,c);
}

void write_Nibble(int rs, unsigned int data){
	GPIO_output(1,enable_mask);
	GPIO_output(rs,rs_mask);
	
	GPIO_output(data, data_mask);
}
