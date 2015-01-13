rootPath = /home/user/Desktop/host-se1/se1
incPath = $(rootPath)/includes
libsPath = $(rootPath)/libs
sourcesPath = /home/user/Desktop/host-se1/se1/sources/

LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
LDSCRIPT = /home/user/Desktop/host-se1/se1/bsp/ldscript_ram

ARM = arm-none-eabi-

Ainsight = $(ARM)insight
Agcc = $(ARM)gcc
Ald = $(ARM)ld
Aas = $(ARM)as

insight: App.axf
	$(Ainsight) App.axf

App.axf : lcd.o initSam.o gpio.o timer.o rtc.o led.o App.o Button.o
	$(Ald) lcd.o initSam.o gpio.o timer.o rtc.o led.o App.o Button.o -T $(LDSCRIPT) $(LIBGCC) -o App.axf

App.o: App.c
	$(Agcc) -c -g App.c -o App.o	

Button.o: Button.c
	$(Agcc) -c -g Button.c -o Button.o

gpio.o: gpio.c
	$(Agcc) -c -g gpio.c -o gpio.o

lcd.o: lcd.c
	$(Agcc) -c -g lcd.c -o lcd.o
	
led.o: led.c
	$(Agcc) -c -g led.c -o led.o
	
rtc.o: rtc.c
	$(Agcc) -c -g rtc.c -o rtc.o

timer.o: timer.c
	$(Agcc) -c -g timer.c -o timer.o

initSam.o: initSam.S
	$(Aas) initSam.S -o initSam.o -g

clean: 
	rm *.o *.axf
