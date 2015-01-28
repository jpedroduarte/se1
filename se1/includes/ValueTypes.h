#ifndef VALUETYPES_h
#define VALUETYPES_h

#define TEMP 3
#define MM 2
#define YEAR 4

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

void n2str(char *str, int n, int p);

void year2str(char *str, int n, int p);


#endif
