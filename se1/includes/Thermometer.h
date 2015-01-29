/** @file termometer.h
*  termometer module header.
*/

#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "/home/user/Desktop/host-se1/se1/includes/I2C.h"
#include "/home/user/Desktop/host-se1/se1/includes/timer.h"

/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura
*/
unsigned int THERM_getActualTemperature();

/**
* Devolve o valor maximo da temperatura
* @return retorna o valor maximo da temperatura
*/
unsigned int THERM_getMaxTemperature();

/**
* Devolve o valor minimo da temperatura
* @return retorna o valor minimo da temperatura
*/
unsigned int THERM_getMinTemperature();


/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura actual
*/
void THERM_convertTemperature(char* ptr, int pos, unsigned short temperature);

/**
* Devolve a temperatura
* @param ptr pointer para a formatação da escrita
* @param temp posição onde ser quer começar a escrever
* @param temperature temperatura corrente
* @return retorna a temperatura
*/
void THERM_getLogTemperature(char* ptr, int pos, unsigned short temperature);


char THERM_compareTemperature(short temp1, short temp2);
short THERM_Temp2short(int degrees, int decDegres);

#endif
