#root Path
rootPath = /home/user/Desktop/host-se1/se1/
#includes Path
incPath = $(rootPath)includes/
#libraries Path
libsPath = $(rootPath)libs/
#bsp Path
bspPath = $(rootPath)bsp/

#GCC Library
LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
#C Library
LIBC = -L/usr/local/arm-tools/arm-2009q1/arm-none-eabi/lib/ -lc
#Script RAM
LDSCRIPT = $(bspPath)ldscript_ram
#init
OINIT = $(bspPath)initSam.o
SINIT = $(bspPath)initSam.S

#LIBS
lpc = lpc2106
lcd = lcd
led = led
but = button

LIBLPC = $(libsPath)lib$(lpc).a
LIBLCD = $(libsPath)lib$(lcd).a
LIBLED = $(libsPath)lib$(led).a
LIBBUTTON = lib$(but).a

ILIBLPC = -L$(libsPath) -l$(lpc)
ILIBLCD = -L$(libsPath) -l$(lcd)
ILIBLED = -L$(libsPath) -l$(led)
ILIBBUT = -L$(libsPath) -l$(but)

IALLLIBS = $(ILIBLCD) $(ILIBLED) $(ILIBBUT) $(ILIBLPC) $(LIBC) $(LIBGCC) 

#ARN
ARM = arm-none-eabi-

#ARM insight -> debug
Ainsight = $(ARM)insight
#ARM gcc -> C compiler
Agcc = $(ARM)gcc
#ARM ld -> Linker
Ald = $(ARM)ld
#ARM ar -> library
Aar = %(ARM)ar
#ARM as -> Assembler
Aas = $(ARM)as

insight: App.axf
	$(Ainsight) App.axf

App.axf :  App.o Menu.o Manager.o I2C.o
	$(Ald) $(OINIT) App.o Menu.o Manager.o I2C.o -T $(LDSCRIPT) $(IALLLIBS) -o App.axf

App.o: App.c
	$(Agcc) -c -g App.c -o App.o	

Manager.o: Manager.c
	$(Agcc) -c -g Manager.c -o Manager.o

Menu.o: Menu.c
	$(Agcc) -c -g Menu.c -o Menu.o
	
I2C.o: I2C.c
	$(Agcc) -c -g I2C.c -o I2C.o

clean: 
	rm *.o *.axf
