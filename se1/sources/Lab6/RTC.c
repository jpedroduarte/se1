#include "RTC.h";

/* Faz a iniciação do sistema para permitir o acesso ao periférico RTC, que é iniciado com os valores do parâmetro datetime.
Nota: A struct tm está definida na biblioteca standard da linguagem C. */
void RTC_Init(struct tm *dateTime){
	RTC.ILR= 	0x00000000; 	//Interrupt Location Register
	//RTC.CTC;				//Clock Tick Counter Register
	RTC.CCR= 	0x00000000;	//Clock Control Register
	RTC.CIIR= 	0x00000000;	//Counter Increment Interrupt Register
	RTC.AMR= 	0x00000000;	//Alarm Mask Register- Not Used
	//RTC.CTIME0;				//Read-Only dateTime->tm_wday<<24| dateTime->tm_hour<<16| dateTime->tm_min << 8 | dateTime->tm_sec;
	//RTC.CTIME1; 			//Read-Only dateTime->tm_year| dateTime->tm_mon << 8 | dateTime->tm_mday;
	//RTC.CTIME2;				//Read-Only
	
	/* Time Counter Group */
	
	RTC.SEC=	dateTime->tm_sec;
	RTC.MIN=	dateTime->tm_min; 
	RTC.HOUR=	dateTime->tm_hour;
	RTC.DOM=	dateTime->tm_mday;
	RTC.DOW=	dateTime->tm_wday;
	RTC.DOY=	dateTime->tm_yday;
	RTC.MONTH=	dateTime->tm_mon;
	RTC.YEAR=	dateTime->tm_year;
	
	//RTC.RESERVED[8];		//Dummy
	
	/* Alarm Register Group - Not Used
	RTC.ALSEC; 
	RTC.ALMIN; 
	RTC.ALHOUR,
	RTC.ALDOM,
	RTC.ALDOW, 
	RTC.ALDOY, 
	RTC.ALMON, 
	RTC.ALYEAR;
	* 
	/* Reference Clock Divider */
	
	RTC.PREINT= (LPC2106_PCLK/32768) - 1;
	RTC.PREFRAC= LPC2106_PCLK - ((RTC.PREINT+1) * 32768);
}

/* Devolve em dateTime o valor corrente do RTC. */
void RTC_GetValue(struct tm *dateTime){
	dateTime->tm_sec=	RTC.SEC;
	dateTime->tm_min=	RTC.MIN;
	dateTime->tm_hour=	RTC.HOUR;
	dateTime->tm_mday=	RTC.DOM;
	dateTime->tm_wday=	RTC.DOW;	
	dateTime->tm_yday=	RTC.DOY;	
	dateTime->tm_mon=	RTC.MONTH;	
	dateTime->tm_year=	RTC.YEAR;
}
/* Atualiza os registos do RTC com os valores do parâmetro dateTime. */
void RTC_SetValue(struct tm *dateTime){
	RTC.SEC=	dateTime->tm_sec;
	RTC.MIN=	dateTime->tm_min; 
	RTC.HOUR=	dateTime->tm_hour;
	RTC.DOM=	dateTime->tm_mday;
	RTC.DOW=	dateTime->tm_wday;
	RTC.DOY=	dateTime->tm_yday;
	RTC.MONTH=	dateTime->tm_mon;
	RTC.YEAR=	dateTime->tm_year;
}
