/** @file LCD.h
*  LCD module header.
*/
#ifndef LCD_H
#define LCD_H

/**
* Envia um nibble para o periferico
* @param rs Quando 0 indica um comando, quando 1 indica data
* @param data Data a ser transmitida
*/
void write_Nibble(int rs, unsigned int data);

/**
* Envia um byte para o periferico
* @param rs Quando 0 indica um comando, quando 1 indica data
* @param data Data a ser transmitida
*/
void write_Byte(int rs, int data);

/**
* Faz a iniciação do sistema para permitir o acesso ao periférico
* utilizando 2 linhas com 16 colunas e comunicação a 4 bits. 
*/
void LCD_Init(void);

/**
 * Escreve um carácter na posição corrente do cursor
 * @param ch caracter que se pretende escrever
 */
void LCD_WriteChar(char ch);

/**
 * Escreve uma string na posição corrente do cursor
 * @param str string que se pretende escrever
*/
void LCD_WriteString(char *str);

/**
* Posiciona o cursor na posição indicada no mostrador. 
* @param x Indica a linha
* @param y Indica a coluna
*/
void LCD_Goto(int x, int y);

/**
* Limpa o visor, usando o comando disponível na API do periférico. 
*/
void LCD_Clear(void);

/**
 * Liga o LDC
 */
void LCD_On(void);

/**
 * Desliga o LDC
 */
void LCD_Off(void);

#endif
