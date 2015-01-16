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

typedef struct {
	LPC2xxx_REG IR;
	LPC2xxx_REG TCR;
	LPC2xxx_REG TC;
	LPC2xxx_REG PR;
	LPC2xxx_REG PC;
	LPC2xxx_REG MCR;
	LPC2xxx_REG MR0;
	LPC2xxx_REG MR1;
	LPC2xxx_REG MR2;
	LPC2xxx_REG MR3;
	LPC2xxx_REG CCR;
	LPC2xxx_REG CR0;
	LPC2xxx_REG CR1;
	LPC2xxx_REG CR2;
	LPC2xxx_REG CR3;
	LPC2xxx_REG EMR;
	LPC2xxx_REG RESERVED[12]; /* Dummy */
	LPC2xxx_REG CTCR;
} LPC210X_TC;


#endif 
