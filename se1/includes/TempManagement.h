#ifndef TEMPMANAGEMENT_H
#define TEMPMANAGEMENT_H

typedef struct Cooling{
	int pinMask;
	int turn;
} Cooling;

typedef struct Heating{
	int pinMask;
	int turn;
} Heating;

typedef struct TempAlarm{
	int pinMask;
	int turn;
} Alarm;



typedef enum TURN{
	ON =1,
	OFF =0
} TURN;


void TempManagement_Init(int pinMask);
void TempManagement_TURN(int pinMask, TURN t); 

Alarm Alarm_Init(int pinId);
void Alarm_ON(Alarm *a);
void Alarm_OFF(Alarm *a);

Cooling Cooling_Init(int pinId);
void Cooling_ON(Cooling *c);
void Cooling_OFF(Cooling *c);

Heating Heating_Init(int pinId);
void Heating_ON(Heating *h);
void Heating_OFF(Heating *h);

#endif
