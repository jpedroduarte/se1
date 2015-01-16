#ifndef _RTC_H
#define _RTC_H

#include <time.h>
#include "LPC2xxx.h"
#include "LPC2106.h"

void RTC_Init(struct tm *dateTime);

void RTC_GetValue(struct tm *dateTime);

void RTC_SetValue(struct tm *dateTime);

#endif

