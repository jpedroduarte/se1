#include <stdio.h>
#include "Flash.h"

int main(){
	//unsigned int a= FLASH_EraseSectors(1,2);
	char* string = {'R','E','D','U'};
	int size = 256;
	char src[size];
	int i;
	for(i = 0 ; i<size ; ++i){
		src[i] = (char)i;
	}
	
	unsigned int* sector1=0x00002000;
	unsigned int c= FLASH_WriteBlock(sector1,src,size);
	unsigned int b= FLASH_VerifyData(sector1,src,size);
	return 0;
}

