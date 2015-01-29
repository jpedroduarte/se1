/** @file I2C.c
*  I2C module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/Log.h"

LOG log = {0};
LOG *pLog;

/**
* Inicia o Log
*/
void LOG_Init(){
	pLog = &log;
	pLog->size = 168;
	pLog->currSize = 0;
	pLog->currPos = 0;
	pLog->fully = 0;
}

/**
* Mostra o próximo registo
*/
void LOG_ShowNext(){
	if(pLog->currSize ==0)
		return;
	int curr = (pLog->currPos) +1;
	if(curr > pLog->currSize)
		curr = 0;
	pLog->currPos = curr;
	TempReg *ptr = (TempReg*)(pLog->temps);
	ptr += curr;
	LOG_ShowRegist(ptr);
}

/**
* Mostra o anterior registo
*/
void LOG_ShowPrev(){
	if(pLog->currSize ==0)
	return;
	int curr = pLog->currPos - 1;
	if(curr < 0)
		curr = pLog->currSize;
	pLog->currPos = curr;
	TempReg *ptr = (TempReg*)(pLog->temps);
	ptr += curr;
	LOG_ShowRegist(ptr);
}

/**
* Efectua um registo de uma temperatura para uma determinada hora
* @param tr ponteiro para um TempReg
* @param dateTime ponteiro para uma estrutura do tipo tm
* @param temp temperatura que se pretende registar
*/
void LOG_RegistDataTemp(TempReg *tr, struct tm *dateTime, unsigned int temp){
	tr->timeData = Data2Int(dateTime);
	tr->temp = (short)temp;
}

/**
* Mostra um determinado registo
* @param tr ponteiro para um TempReg
*/
void LOG_ShowRegist(TempReg *tr){
	char *str = "00:00 00-00-0000";
	struct tm *dateTime = {0};
	Int2Data(tr->timeData,dateTime);
	n2str(str,dateTime->tm_hour & 0x1F,0);
	n2str(str,dateTime->tm_min & 0x3F,3);
	n2str(str,dateTime->tm_mday & 0x1F,6);
	n2str(str,dateTime->tm_mon & 0x0F,9);
	year2str(str,dateTime->tm_year,12);
	char *temp = "Tmp= S000,0000.C";
	getLogTemperature(temp,5,tr->temp);
	LCD_Clear();
	LCD_WriteString(str);
	LCD_Goto(1,0);
	LCD_WriteString(temp);
}

/**
* Converte uma data para um inteiro
* @param dateTime ponteiro para uma estrutura do tipo tm
* @return returna a data comprimida num inteiro
*/
int Data2Int(struct tm *dateTime){
	int res = 0;
	res |= ((dateTime->tm_hour & 0x1F) << HOURPOS);
	res |= ((dateTime->tm_min & 0x3F) << MINPOS);
	res |= ((dateTime->tm_mday & 0x1F) << DAYPOS);	
	res |= ((dateTime->tm_mon & 0x0F) << MONTHPOS);
	res |= (dateTime->tm_year & 0xFFF);
	return res;
}

/**
* Converte um inteiro para uma data
* @param data data que se encontra comprimida
* @param dateTime ponteiro para uma estrutura do tipo tm
*/
void Int2Data(int data, struct tm *dateTime){
	dateTime->tm_hour = ((data & HOURMASK) >> HOURPOS);
 	dateTime->tm_min  = ((data & MINMASK) >> MINPOS);
	dateTime->tm_mday = ((data & DAYMASK) >> DAYPOS);	
	dateTime->tm_mon  = ((data & MONTHMASK) >> MONTHPOS);
	dateTime->tm_year = data & 0xFFF;
}
