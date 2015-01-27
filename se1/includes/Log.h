#ifndef LOG_h
#define LOG_h

typedef struct tempReg{
	char hour;
	char temp;
} TempReg;

void WriteData(char hour, char temp);
char* ShowTemp(TempReg tr);

#endif
