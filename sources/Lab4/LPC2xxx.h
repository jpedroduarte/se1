#ifndef LPC2xxx.h
#define LPC2xxx.h

typedef struct{
	volatile unsigned int IOPIN;
	volatile unsigned int IOSET;
	volatile unsigned int IODIR;
	volatile unsigned int IOCLR;
} GPIO_DSC;

#endif 
