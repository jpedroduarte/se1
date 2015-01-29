#include "keyboard.h"
#include "GPIO.h"

unsigned int col_mask  = 0x00000F00;
unsigned int line_mask = 0x000000F0;
unsigned int keys[16];
char key_idx[] = { 0xFF, 0, 1, 0xFF, 2, 0xFF, 0xFF, 0xFF ,3};



/**
* Faz a iniciação do sistema para permitir o acesso ao periférico.
* @param layout vetor com os códigos das 16 teclas
*/
void KBD_Init(unsigned int layout[16]){
	GPIO_config(col_mask, col_mask | line_mask, 0);
	int i;
	for(i = 0; i<16; ++i)
		keys[i] = layout[i];
}

/**
* Verifica se uma tecla foi precionada
* @return 1 se existe alguma tecla pressionada e 0 no caso contrário.
*/
int KBD_Hit(void){
	unsigned input = GPIO_input();
	int res = (input & line_mask) >>4 ;
	
	return res != 0;
}

/**
* Devolve o código da tecla pressionada, é bloqueante.
* @return código da tecla pressionada
*/
int KBD_Read(void){
	unsigned int i, init_col = 0x100, last_col = 0x800;
	unsigned int line, aux, col;
	for(i=init_col;  ; i<<=1){
		if(i > last_col)
			i=init_col;
		GPIO_output(i, i); //injetar 1 na coluna
		if(KBD_Hit()){
			unsigned in = (GPIO_input() & line_mask)>>4;
			line = key_idx[in];
			unsigned c = i>>8;
			col = key_idx[c];
			return keys[4 * line + col];
		}
		GPIO_output(0, i);
	}
}
	
