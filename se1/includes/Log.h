/** @file LOG.h
*  LOG module header.
*/
#ifndef LOG_h
#define LOG_h

#include <time.h>
#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"

/**
* Define as posiçoes e mascaras dos componentes de uma data e hora.
*/
#define HOURMASK 0xF8000000
#define HOURPOS  27
#define MINMASK 0x07E00000
#define MINPOS  21
#define DAYMASK 0x001F0000
#define DAYPOS  16
#define MONTHMASK 0x0000F000
#define MONTHPOS  12
#define YEARMASK 0x00000FFF

/**
* Define o tipo de registo feito
*/
typedef struct tempReg{
 int timeData;
 short temp;
} TempReg;

/**
* Define o controlador do Log
*/
typedef struct logCTRL{
 int size;
 int currSize;
 int currPos;
 int fully;
 TempReg temps[168];
} LOG;

/**
* Inicia o Log
*/
void LOG_Init();

/**
* Efectua um registo de uma temperatura para uma determinada hora
* @param tr ponteiro para um TempReg
* @param dateTime ponteiro para uma estrutura do tipo tm
* @param temp temperatura que se pretende registar
*/
void LOG_RegistDataTemp(TempReg *tr, struct tm *dateTime, unsigned int temp);

/**
* Mostra um determinado registo
* @param tr ponteiro para um TempReg
*/
void LOG_ShowRegist(TempReg *tr);

/**
* Converte uma data para um inteiro
* @param dateTime ponteiro para uma estrutura do tipo tm
* @return returna a data comprimida num inteiro
*/
int Data2Int(struct tm *dateTime);

/**
* Converte um inteiro para uma data
* @param data data que se encontra comprimida
* @param dateTime ponteiro para uma estrutura do tipo tm
*/
void Int2Data(int data, struct tm *dateTime);

/**
* Mostra o próximo registo
*/
void LOG_ShowNext();

/**
* Mostra o anterior registo
*/
void LOG_ShowPrev();

#endif
