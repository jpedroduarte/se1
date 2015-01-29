#ifndef LOG_h
#define LOG_h

#include <time.h>
#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"

#define HOURMASK 0xF8000000
#define HOURPOS  27
#define MINMASK 0x07E00000
#define MINPOS  21
#define DAYMASK 0x001F0000
#define DAYPOS  16
#define MONTHMASK 0x0000F000
#define MONTHPOS  12
#define YEARMASK 0x00000FFF

typedef struct tempReg{
 int timeData;
 short temp;
} TempReg;



typedef struct logCTRL{
 int size;
 int currSize;
 int currPos;
 int fully;
 TempReg temps[168];
} LOG;

void LOG_Init();

void LOG_RegistDataTemp(TempReg *tr, struct tm *dateTime, unsigned int temp);

void LOG_ShowRegist(TempReg *tr);

int Data2Int(struct tm *dateTime);

void Int2Data(int data, struct tm *dateTime);

void LOG_ShowNext();

void LOG_ShowPrev();

#endif
