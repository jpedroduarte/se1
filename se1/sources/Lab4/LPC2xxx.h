#ifndef LPC2xxx_h
#define LPC2xxx_h

typedef volatile unsigned int LPC2xxx_REG;

typedef struct{
	LPC2xxx_REG IOPIN;
	LPC2xxx_REG IOSET;
	LPC2xxx_REG IODIR;
	LPC2xxx_REG IOCLR;
} GPIO_DSC;

typedef struct {
	/* Miscellaneous Register Group */
	LPC2xxx_REG ILR, CTC, CCR, CIIR, AMR;
	LPC2xxx_REG CTIME0, CTIME1, CTIME2;
	/* Time Counter Group */
	LPC2xxx_REG SEC, MIN, HOUR;
	LPC2xxx_REG DOM, DOW, DOY, MONTH, YEAR;
	LPC2xxx_REG RESERVED[8]; /* Dummy */
	/* Alarm Register Group */
	LPC2xxx_REG ALSEC, ALMIN, ALHOUR, ALDOM, ALDOW, ALDOY, ALMON, ALYEAR;
	/* Reference Clock Divider */
	LPC2xxx_REG PREINT, PREFRAC;
} LPC210X_RTC;



#endif 
