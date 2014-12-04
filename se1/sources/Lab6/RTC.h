#ifndef RTC_H
#define RTC_H

#include "LPC2xxx.h"
#include "LPC2106.h"
#include <time.h>

void RTC_Init(struct tm *dateTime);

void RTC_GetValue(struct tm *dateTime);

void RTC_SetValue(struct tm *dateTime);

#endif
