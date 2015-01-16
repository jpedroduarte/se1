#root Path
rootPath = /home/user/Desktop/host-se1/se1/
#includes Path
incPath = $(rootPath)includes/
#libraries Path
libsPath = $(rootPath)libs/

LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
LDSCRIPT = /home/user/Desktop/host-se1/se1/bsp/ldscript_ram

lpc = lpc2106
lcd = lcd
led = led

LIBLPC = $(libsPath)lib$(lpc).a
LIBLCD = $(libsPath)lib$(lcd).a
LIBLED = $(libsPath)lib$(led).a

ILIBLPC = -L$(libsPath) -l$(lpc)
ILIBLCD = -L$(libsPath) -l$(lcd)
ILIBLED = -L$(libsPath) -l$(led)

insight: Lab6.axf
	arm-none-eabi-insight Lab6.axf

# LAB6 Withlibraries
Lab6.axf:  main.o initSam.o 
	arm-none-eabi-ld main.o initSam.o -T $(LDSCRIPT) $(ILIBLCD) $(ILIBLED) $(ILIBLPC) $(LIBGCC) -o Lab6.axf

#
#Lab6.axf: lcd.o main.o initSam.o gpio.o timer.o rtc.o led.o
#	arm-none-eabi-ld lcd.o main.o initSam.o gpio.o timer.o rtc.o led.o -T $(LDSCRIPT) $(LIBGCC) -o Lab6.axf

#gpio.o: gpio.c
#	arm-none-eabi-gcc -c -g gpio.c -o gpio.o

#lcd.o: lcd.c
#	arm-none-eabi-gcc -c -g lcd.c -o lcd.o
	
#led.o: led.c
#	arm-none-eabi-gcc -c -g led.c -o led.o
	
#rtc.o: rtc.c
#	arm-none-eabi-gcc -c -g rtc.c -o rtc.o

#timer.o: timer.c
#	arm-none-eabi-gcc -c -g timer.c -o timer.o

main.o: main.c
	arm-none-eabi-gcc -c -g main.c -o main.o

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g

clean:
	clear
	rm *.o *.axf
	
