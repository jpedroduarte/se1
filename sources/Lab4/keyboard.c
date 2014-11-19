#include "keyboard.h"
#include "GPIO.c"

//mudar as mascaras do config para aqui
unsigned int col_mask  = 0x00001E00;
unsigned int line_mask = 0x000001E0;
unsigned int keys[16];

/* Faz a iniciação do sistema para permitir o acesso ao periférico. Para tal,
recebe como parâmetro o vetor com os códigos das 16 teclas (layout). */
void KBD_Init(unsigned int layout[16]){
	GPIO_config(0x00001E00, 0x0001FE00, 0);
	int i;
	for(i = 0; i<16; ++i)
		keys[i] = layout[i];
}

/* Devolve 1 se existe alguma tecla pressionada e 0 no caso contrário. Não é
bloqueante. */
int KBD_Hit(void){
	return GPIO_input() & line_mask;
}

/* Devolve o código da tecla pressionada. É bloqueante. */
int KBD_Read(void){
	unsigned int line, aux, col;
	for(col=0x00000200; ; col<<=1){
		aux = 0;
		if(col == 0x00002000)
			col=0x00000200;
		GPIO_output(1, col); //injetar 1 na coluna
		if(KBD_Hit){
			line = GPIO_input() & line_mask;
			line>>=5;
			aux = col>>10;
			return keys[(aux-1)+(line-1)];
		}
	}
}
	
