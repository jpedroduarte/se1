 /** @file memory 
 * Memory module
 */
#include <string.h>
#include "memory.h"

/**
 * Memorty station store address
 */
#define MEMORY_STORE_ADDRESS (0x0001A000) 

/**
 *  Memory temp values
 */
Temp_Memory temp_mem;	

/**
 * Obter a temperatura numa deternimada posiçao
 * @param i posiçao na memoria
 * @return o conteudo da posiçao passada como parametro
 */
unsigned int Mem_get(unsigned int i){
	return temp_mem.memory[i];
}

/**
 * Gravar as temperaturas na flash
 */
void Write_Memory_Data(){
	FLASH_WriteData((void *) MEMORY_STORE_ADDRESS, &temp_mem, sizeof(Temp_Memory));
}

/**
 * Altera o conteudo da posiçao indicada
 * @param position Posiçao na memoria
 * @param value valor que se pretende colocar na position
 */
void Write_At(unsigned int position, unsigned int value){
	temp_mem.memory[position] = value;
	Write_Memory_Data();
}

/**
 * Ler o que esta escrito na flash
 */
void Load_Memory_Data(){
	memcpy(&radio_mem, (void *) MEMORY_STORE_ADDRESS, sizeof(Temp_Memory));
}
