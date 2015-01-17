/** @file RTC.h
*  RTC module header.
*/
#ifndef RTC_H
#define RTC_H

#include "LPC2xxx.h"
#include "LPC2106.h"
#include <time.h>

/**
* Faz a iniciação do sistema para permitir o acesso ao periférico RTC.
* @param dateTime Estrutura com os valores de iniciaçao do RTC
* Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_Init(struct tm *dateTime);

/**
* Devolve o valor corrente do RTC.
* @param dateTime Estrutura onde sera comolcados os valores actuais do RTC
* Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_GetValue(struct tm *dateTime);

/**
* Actualiza os valores do RTC com os valores do parâmetro dateTime.
* @param dateTime Estrutura com os valores para actualizar o RTC
* Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_SetValue(struct tm *dateTime);

#endif