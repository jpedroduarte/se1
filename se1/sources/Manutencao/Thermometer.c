/** @file thermometer.h
*  termometer module header.
*/
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"

/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura
*/
unsigned int getActualTemperature(){
	unsigned int a= 0x51;
	unsigned int* data = &a;
	unsigned t = I2C_Transfer(0x90, 1, (void*)data, 1, I2C_FREQ);
	a = 0xAA;
	t = I2C_Transfer(0x90, 1, (void*)data, 2, I2C_FREQ);
	a=a;
	return *data;
}

/**
* Devolve o valor maximo da temperatura
* @return retorna o valor maximo da temperatura
*/
unsigned int getMaxTemperature(){
	char data[1] = {0xA1};
	return I2C_Transfer(0x90, 1, (void*)data, 2, I2C_FREQ);
}

/**
* Devolve o valor minimo da temperatura
* @return retorna o valor minimo da temperatura
*/
unsigned int getMinTemperature(){
	char data[1] = {0xA2};
	return I2C_Transfer(0x90, 1, (void*)data, 2, I2C_FREQ);
}


/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura actual
*/
char* convertTemperature(char* ptr, int pos, unsigned short temperature){
	unsigned short temp = temperature & 0xFF00;
	int signal = (temp & 0x8000);
	if (signal == 0x8000){ //por o sinal de menos
		*(ptr + pos) = '-';
	}
	else
		*(ptr + pos) = '+';

	temp = (temp & 0x7F00) >> 8;

	*(ptr + pos + 1) = '0' + (temp / 100);
	*(ptr + pos + 2) = '0' + ((temp % 100) / 10);
	*(ptr + pos + 3) = '0' + ((temp % 100) % 10);
}

/**
* Devolve a temperatura
* @param ptr pointer para a formatação da escrita
* @param temp posição onde ser quer começar a escrever
* @param temperature temperatura corrente
* @return retorna a temperatura
*/
void getLogTemperature(char* ptr, int pos, unsigned short temperature){

	unsigned short temp = temperature & 0xFF00;
	int signal = (temp & 0x8000);
	int peso[] = { 5000, 2500, 1250, 625 };
	unsigned short neg = ~(temp >> 4);
	unsigned short positive = (temp >> 4);
	int frac;
	if (signal == 0x8000){ //por o sinal de menos
		*(ptr + pos) = '-';
	}
	else
		*(ptr + pos) = '+';

	temp = (temp & 0x7F00) >> 8;

	*(ptr + pos + 1) = '0' + (temp / 100);
	*(ptr + pos + 2) = '0' + ((temp % 100) / 10);
	*(ptr + pos + 3) = '0' + ((temp % 100) % 10);

	//versao negativa
	if (signal){
		frac = (peso[3] * (neg * 0x8)) + (peso[2] * (neg * 0x4)) + (peso[1] * (neg * 0x2)) + (peso[0] * (neg * 0x1)) + peso[3];
	}
	else{
		frac = (peso[3] * (positive * 0x8)) + (peso[2] * (positive * 0x4)) + (peso[1] * (positive * 0x2)) + (peso[0] * (positive * 0x1));
	}
	*(ptr + pos + 5) = '0' + (frac / 1000);
	*(ptr + pos + 6) = '0' + ((frac % 1000) / 100);
	*(ptr + pos + 7) = '0' + ((frac % 100) / 10);
	*(ptr + pos + 8) = '0' + ((frac % 100) % 10);

}
