/** @file thermometer.h
*  termometer module header.
*/
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"

/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura
*/
unsigned int THERM_getActualTemperature(){
	unsigned int a = 0x51;
	I2C_Transfer(0x90, 0, &a, 1, I2C_FREQ);
	TMR0_Delay(1000);
	a= 0xAA;
	I2C_Transfer(0x90, 0, &a, 1, I2C_FREQ);
	char buf[2] = {0,0};
	I2C_Transfer(0x90, 1, &buf, 2, I2C_FREQ);
	return (buf[0]<<8) | buf[1];
}

/**
* Devolve o valor maximo da temperatura
* @return retorna o valor maximo da temperatura
*/
unsigned int THERM_getMaxTemperature(){
	char data[1] = {0xA1};
	return I2C_Transfer(0x90, 1, (void*)data, 2, I2C_FREQ);
}

/**
* Devolve o valor minimo da temperatura
* @return retorna o valor minimo da temperatura
*/
unsigned int THERM_getMinTemperature(){
	char data[1] = {0xA2};
	return I2C_Transfer(0x90, 1, (void*)data, 2, I2C_FREQ);
}


/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura actual
*/
#define signalMask 0x80
void THERM_convertTemperature(char* ptr, int pos, unsigned short temperature){
	char temp = (temperature & 0xFF00)>>8;
	int signal = (temp & signalMask);
	if (signal == signalMask){ //por o sinal de menos
		*(ptr + pos) = '-';
		temp = ~temp;
	}
	else
		*(ptr + pos) = '+';
	
	*(ptr + pos + 1) = '0' + (temp / 100);
	*(ptr + pos + 2) = '0' + ((temp % 100) / 10);
	*(ptr + pos + 3) = '0' + ((temp % 100) % 10);
}

/**
* Devolve a temperatura
* @param ptr pointer para a formatação da escrita
* @param temp posição onde ser quer começar a escrever
* @param temperature temperatura corrente
* @return retorna a string preenchida em ptr 
*/
void THERM_getLogTemperature(char* ptr, int pos, unsigned short temperature){
	char s = (temperature & 0x8000)>>15;
	THERM_convertTemperature(ptr,pos,temperature);
	pos += 5;
	int peso[] = { 0, 625, 1250, 0,2500, 0, 0, 0, 5000 };
	 char f= (unsigned char)((temperature & 0xF0) >>4);
	int frac = 0,i;
	if(s){
		frac = 625;
		f = ~f;	
	}
	for(i=1 ; i<=8 ; i<<=1){
		frac += peso[f&i];
	}
	*(ptr + pos) = '0' + (frac / 1000);
	*(ptr + pos + 1) = '0' + ((frac % 1000) / 100);
	*(ptr + pos + 2) = '0' + ((frac % 100) / 10);
	*(ptr + pos + 3) = '0' + ((frac % 100) % 10);
}

/**
 * 
 * (1) - temp1 > temp2 ; (0)  temp1 = temp2 ; (-1) temp1<temp2
 * 
 */
int THERM_compareTemperature(short temp1, short temp2){
	return (temp1-temp2);
}

short THERM_Temp2short(char degrees){
	if(degrees > 125 || degrees < -55)
		return -1;
	return (degrees <<8);
}

