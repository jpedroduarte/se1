#ifndef _LIBLPC2106_H_
#define _LIBLPC2106_H_

/*
 * 
 * LPC2xxx
 *
 */
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

/*
 * 
 * LPC206
 *
 */
 
/****************************************************************************\
| CLOCK DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_MAIN_OSC 14745600 // Main #000000
#define LPC2106_CCLK LPC2106_MAIN_OSC // Output PLL Clock
#define LPC2106_PCLK LPC2106_CCLK / 4 // Peripheral Clock

/****************************************************************************\
| BASE ADDRESS DEFINITIONS FOR LPC2106
\*********************************************#000000#000000*******************************/
#define GPIO_base 0xE0028000 
#define GPIO (*((GPIO_DSC *)GPIO_base))

#define LPC2106_BASE_TC0 ( *( (LPC210X_TC *) 0xE0004000) ) //TIMER 0
#define LPC2106_BASE_TC1 ( *( (LPC210X_TC *) 0xE0008000) ) //TIMER 1
#define LPC2106_BASE_RTC ( *( (LPC210X_RTC *) 0xE0024000) ) //RTC

/*
 * 
 * GPIO
 *
 */
 
void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue);

void GPIO_output(unsigned int value, unsigned int mask);

unsigned int GPIO_input();
 
 /*
 * 
 * RTC
 *
 */

#include <time.h>

void RTC_Init(struct tm *dateTime);

void RTC_GetValue(struct tm *dateTime);

void RTC_SetValue(struct tm *dateTime);

/*
 * 
 * TIMER
 *
 */
 
void TMR0_Init(unsigned int frequency);

unsigned int TMR0_GetValue(void);

unsigned int TMR0_Elapsed(unsigned int lastRead);
 

#endif
