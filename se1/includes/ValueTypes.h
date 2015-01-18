#ifndef VALUETYPES_h
#define VALUETYPES_h_h

typedef enum valType{
	TEMP =  3, MM = 2  , YEAR = 4
}ValType;

typedef struct SetPos{
	int x;
	int y;
	int size;
}SetPos;

typedef struct SetVal{
	int min;
	int max;
	int curr;
}SetVal;

typedef struct Seter{
	SetPos pos;
    SetVal val;
}Seter;

#endif
