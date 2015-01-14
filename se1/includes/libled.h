#ifndef _LIBLED_H_
#define _LIBLED_H_

#include "LIBLPC2106.h"

/*
 * 
 * LED
 * 
 */
 
void LED_Init(int pinId, int state);

int LED_GetState(void);

void LED_SetState(int state);

#endif
