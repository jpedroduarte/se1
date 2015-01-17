#ifndef _LPC2106_H_
#define _LPC2106_H_

#include "LPC2xxx.h" 

/****************************************************************************\
| CLOCK DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_MAIN_OSC 		14745600 				// Main Oscillator
#define LPC2106_CCLK 			LPC2106_MAIN_OSC 		// Output PLL Clock
#define LPC2106_PCLK 			LPC2106_CCLK/4 			// Peripheral Clock
/****************************************************************************\
| BASE ADDRESS DEFINITIONS FOR LPC2106
\****************************************************************************/
#define TIMER0 			 ( *( (LPC210X_TC 	*) 0xE0004000) )
#define TIMER1			 ( *( (LPC210X_TC 	*) 0xE0008000) )
#define RTC 			 ( *( (LPC210X_RTC	*) 0xE0024000) )
#define GPIO 			 ( *( (GPIO_DSC 	*) 0xE0028000) )
#define LPC2106_BASE_PCB ( *( (LPC210X_PCB 	*) 0xE002C000) )
#define IAP_LOCATION						   0x7ffffff1
#endif
