#include "keyboard.h"
#include "GPIO.c"

//mudar as mascaras do config para aqui
unsigned int col_mask  = 0x000000F0;
unsigned int line_mask = 0x0000000F;
unsigned int keys[16];
char key_idx[] = { 0xFF, 0, 1, 0xFF, 2, 0xFF, 0xFF, 0xFF ,3};



/* Faz a iniciação do sistema para permitir o acesso ao periférico. Para tal,
recebe como parâmetro o vetor com os códigos das 16 teclas (layout). */
void KBD_Init(unsigned int layout[16]){
	
	GPIO_config(col_mask, col_mask | line_mask, 0);
	int i;
	for(i = 0; i<16; ++i)
		keys[i] = layout[i];
}

/* Devolve 1 se existe alguma tecla pressionada e 0 no caso contrário. Não é
bloqueante. */
int KBD_Hit(void){
	int res = GPIO_input() & line_mask;
	
	return res;
}

/* Devolve o código da tecla pressionada. É bloqueante. */
int KBD_Read(void){
	unsigned int i, init_col = 0x10, last_col = 0x80;
	unsigned int line, aux, col;
	
	for(i=init_col;  ; i<<=1){
		if(i == last_col)
			i=init_col;
		GPIO_output(i, i); //injetar 1 na coluna
		if(KBD_Hit()){
			int aux_line = GPIO_input() & line_mask;
			line = key_idx[GPIO_input() & line_mask];
			col = key_idx[i>>4];
			return keys[4 * line + col];
		}
		GPIO_output(0, i);
	}
}
	
