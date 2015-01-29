#include <stdio.h>
#include "Flash.h"

int main(){
	//unsigned int a= FLASH_EraseSectors(0,1);
	//char* string = {'R','E','D','U'};
	int size = 512/sizeof(int);
	int src[size];	// int is 4-byte aligned by default, therefor also 2-byte aligned
	int i;
	for(i = 0 ; i<size ; ++i)
		src[i] = 0xAAAABBBB;
		
	int * RAM_P = (int *)&src;	// must be a word boundary
	unsigned int* sector1=(unsigned int *)0x00000800;	//Sector number 0 --must be a 256 byte boundary
	unsigned int c= FLASH_WriteData(sector1,src,size*sizeof(int));
	unsigned int b= FLASH_VerifyData(sector1,src,size*sizeof(int));
	i=0;
	while(i<size) {
		int a = *(sector1+i);
		i++;
	}
	return 0;
}

