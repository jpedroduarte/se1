/** @file LCD.c
*  LCD module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/LCD.h"

/**
 * Mascaras para a comunicaçao com o periferico
 */ 
unsigned int data_mask = 0x00000F00;
unsigned int rs_mask = 0x00002000;
unsigned int enable_mask = 0x00001000;

/**
 * Activa o Enable do periferico
 */
static void setEnable(){
    GPIO_output(enable_mask,enable_mask);
}

/**
 * Desactiva o Enable do periferico
 */
static void resetEnable(){
    GPIO_output(0,enable_mask);
}

/**
* Envia um nibble para o periferico
* @param rs Quando 0 indica um comando, quando 1 indica data
* @param data Data a ser transmitida
*/
void write_Nibble(int rs, unsigned int data){
	rs = rs? rs_mask : 0;
	GPIO_output(rs,rs_mask);
	GPIO_output(data<<8, data_mask);
    setEnable();
    resetEnable();
}

/**
* Envia um byte para o periferico
* @param rs Quando 0 indica um comando, quando 1 indica data
* @param data Data a ser transmitida
*/
void write_Byte(int rs, int c){
	write_Nibble(rs,(c & 0xF0) >> 4);
	write_Nibble(rs,(c & 0x0F));
}

/**
 * Faz a iniciação do sistema para permitir o acesso ao periférico
 * utilizando 2 linhas com 16 colunas e comunicação a 4 bits. 
 */
void LCD_Init(void){
	unsigned int mask = rs_mask|enable_mask|data_mask;
	GPIO_config( mask, mask, 0);

	TMR0_Delay(60);
	write_Nibble(0,0x03);
	
	TMR0_Delay(10);	
	write_Nibble(0,0x03);
	
	TMR0_Delay(5);
	write_Nibble(0,0x3);
	
	TMR0_Delay(10);
	write_Nibble(0,0x2);
	
	TMR0_Delay(10);
	write_Byte(0,0x28);
	
	TMR0_Delay(10);
	write_Byte(0,0x08);
	
	TMR0_Delay(10);
	write_Byte(0,0x01);
	
	TMR0_Delay(10);
	write_Byte(0,0x06);

	TMR0_Delay(10);
	write_Byte(0,0x0F);
	
	TMR0_Delay(10);
	
}

/**
 * Escreve um carácter na posição corrente do cursor
 * @param ch caracter que se pretende escrever
 */
void LCD_WriteChar(char ch){
	write_Byte(1,ch);
}

/**
 * Escreve uma string na posição corrente do cursor
 * @param str string que se pretende escrever
*/
void LCD_WriteString(char *str){
	while(*str){
		char c = *str;
		TMR0_Delay(20);
		write_Byte(1,*str);
		++str;
	}
}

/**
 * Posiciona o cursor na linha e coluna pretendida do mostrador
 * @param x indica a linha
 * @param y indica a coluna
*/
void LCD_Goto(int x, int y){
	int data = (0x80 | x <<6 | (0x3F & y));
	TMR0_Delay(10);
	write_Byte(0,data);
}

/**
 * Limpa o visor, usando o comando disponível na API do periférico. 
*/
void LCD_Clear(void){
	TMR0_Delay(10);
	write_Byte(0,0x01);
}

/**
 * Liga o LDC
 */
void LCD_On(void){
	TMR0_Delay(10);
	write_Byte(0,0x0F);
}

/**
 * Desliga o LDC
 */
void LCD_Off(void){
	TMR0_Delay(10);
	write_Byte(0,0x08);
}

