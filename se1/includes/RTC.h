/** @file RTC.h
*  RTC module header.
*/
#ifndef RTC_H
#define RTC_H

#include "LPC2xxx.h"
#include "LPC2106.h"
#include <time.h>

/**
* Faz a inicia��o do sistema para permitir o acesso ao perif�rico RTC.
* @param dateTime Estrutura com os valores de inicia�ao do RTC
* Nota: A struct tm est� definida na biblioteca standard da linguagem C
*/
void RTC_Init(struct tm *dateTime);

/**
* Devolve o valor corrente do RTC.
* @param dateTime Estrutura onde sera comolcados os valores actuais do RTC
* Nota: A struct tm est� definida na biblioteca standard da linguagem C
*/
void RTC_GetValue(struct tm *dateTime);

/**
* Actualiza os valores do RTC com os valores do par�metro dateTime.
* @param dateTime Estrutura com os valores para actualizar o RTC
* Nota: A struct tm est� definida na biblioteca standard da linguagem C
*/
void RTC_SetValue(struct tm *dateTime);

#endif