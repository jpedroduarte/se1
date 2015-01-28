/** @file memory.h 
 * Memory module header
 */
 
/**
 * Espaço para guardar a temperatura a cada hora durante 1 semana 
 */
#define MEMORY_POSITIONS (168)	

/**
 * Estrutura da memoria
 */
typedef struct temp_memory_struct{
	unsigned int memory[MEMORY_POSITIONS];
	unsigned int actualPosition;
}Temp_Memory;

/**
 * Obter a temperatura numa determinada posiçao
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
