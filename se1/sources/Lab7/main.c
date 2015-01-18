#include <stdio.h>
#include "Flash.h"

int main(){
	FLASH_EraseSectors(1,2);
	char* string = {'R','E','D','U'};
	void* sector1= 0x0x00002000;
	FLASH_WriteBlock(string, sector1, 4);
	unsigned int flag= FLASH_VerifyData(sector1,string,4);
	if(flag==0) printf("Sucess");
}

