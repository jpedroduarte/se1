#ifndef RTC_H
#define RTC_H

void RTC_Init(struct tm *dateTime);

void RTC_GetValue(struct tm *dateTime);

void RTC_SetValue(struct tm *dateTime);

#endif
