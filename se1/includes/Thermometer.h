/** @file termometer.h
*  termometer module header.
*/

#ifndef THERMOMETER_H
#define THERMOMETER_H

/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura
*/
unsigned int getActualTemperature();

/**
* Devolve o valor maximo da temperatura
* @return retorna o valor maximo da temperatura
*/
unsigned int getMaxTemperature();

/**
* Devolve o valor minimo da temperatura
* @return retorna o valor minimo da temperatura
*/
unsigned int getMinTemperature();


/**
* Devolve o valor da temperatura actual
* @return retorna o valor da temperatura actual
*/
char* convertTemperature(char* ptr, int pos, unsigned short temperature);

/**
* Devolve a temperatura
* @param ptr pointer para a formatação da escrita
* @param temp posição onde ser quer começar a escrever
* @param temperature temperatura corrente
* @return retorna a temperatura
*/
void getLogTemperature(char* ptr, int pos, unsigned short temperature);

#endif
