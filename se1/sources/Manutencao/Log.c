#include "/home/user/Desktop/host-se1/se1/includes/Log.h"

LOG log = {0};
LOG *pLog;

void LOG_Init(){
	pLog = &log;
	pLog->size = 168;
	pLog->currSize = 0;
	pLog->currPos = 0;
	pLog->fully = 0;
}

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


void LOG_RegistDataTemp(TempReg *tr, struct tm *dateTime, unsigned int temp){
	tr->timeData = Data2Int(dateTime);
	tr->temp = (short)temp;
}

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

int Data2Int(struct tm *dateTime){
	int res = 0;
	res |= ((dateTime->tm_hour & 0x1F) << HOURPOS);
	res |= ((dateTime->tm_min & 0x3F) << MINPOS);
	res |= ((dateTime->tm_mday & 0x1F) << DAYPOS);	
	res |= ((dateTime->tm_mon & 0x0F) << MONTHPOS);
	res |= (dateTime->tm_year & 0xFFF);
	return res;
}

void Int2Data(int data, struct tm *dateTime){
	dateTime->tm_hour = ((data & HOURMASK) >> HOURPOS);
 	dateTime->tm_min  = ((data & MINMASK) >> MINPOS);
	dateTime->tm_mday = ((data & DAYMASK) >> DAYPOS);	
	dateTime->tm_mon  = ((data & MONTHMASK) >> MONTHPOS);
	dateTime->tm_year = data & 0xFFF;
}
