#root Path
rootPath = /home/user/Desktop/host-se1/se1/
#includes Path
incPath = $(rootPath)includes/
#libraries Path
libsPath = $(rootPath)libs/

#GCC Library
LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
#Script RAM
LDSCRIPT = /home/user/Desktop/host-se1/se1/bsp/ldscript_ram

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

App.axf : $(libsPath)lpc2106.a $(libsPath)lcd.a $(libsPath)led.a App.o Button.o initSam.o
	$(Ald) initSam.o App.o Button.o -T $(LDSCRIPT) $(LIBGCC) $(libsPath)lpc2106.a $(libsPath)lcd.a $(libsPath)led.a -o App.axf

App.o: App.c
	$(Agcc) -c -g App.c -o App.o	

Button.o: Button.c
	$(Agcc) -c -g Button.c -o Button.o

initSam.o: initSam.S
	$(Aas) initSam.S -o initSam.o -g

clean: 
	rm *.o *.axf
