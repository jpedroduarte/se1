#root Path
rootPath = /home/user/Desktop/host-se1/se1/
#includes Path
incPath = $(rootPath)includes/
#libraries Path
libsPath = $(rootPath)libs/
#sources Path
srcPath = $(rootPath)sources/

#GCC Library
LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
#Script RAM
LDSCRIPT = /home/user/Desktop/host-se1/se1/bsp/ldscript_ram
#C Library
LIBC = -L/usr/local/arm-tools/arm-2009q1/arm-none-eabi/lib/ -lc


#Obj

o = o/
OGPIO   = $(o)gpio.o
OLCD    = $(o)lcd.o
OLED    = $(o)led.o
ORTC    = $(o)rtc.o
OTIMER  = $(o)timer.o
OBUTTON = $(o)button.o

#LIBS
lpc = lpc2106
lcd = lcd
led = led
but = button

LIBLPC    = lib$(lpc).a
LIBLCD    = lib$(lcd).a
LIBLED    = lib$(led).a
LIBBUTTON = lib$(but).a 

ILIBLPC = -L$(libsPath) -l$(lpc)
ILIBLCD = -L$(libsPath) -l$(lcd)
ILIBLED = -L$(libsPath) -l$(led)
ILIBBUT = -L$(libsPath) -l$(but)

IALLLIBS = $(ILIBLCD) $(ILIBLED) $(ILIBBUT) $(ILIBLPC)

#SOURCES
Lab6 = $(srcPath)Lab6/
App = $(srcPath)App/


CGPIO   = $(Lab6)gpio.c
CLCD    = $(Lab6)lcd.c
CLED    = $(Lab6)led.c
CRTC    = $(Lab6)rtc.c
CTIMER  = $(Lab6)timer.c
CBUTTON  = $(App)button.c


#ARN
ARM = arm-none-eabi-

#ARM insight -> debug
Ainsight = $(ARM)insight
#ARM gcc -> C compiler
Agcc = $(ARM)gcc
#ARM ld -> Linker
Ald = $(ARM)ld
#ARM ar -> library
Aar = $(ARM)ar
#ARM as -> Assembler
Aas = $(ARM)as

#######################

create: libLpc libLcd libLed libBut
	ls *.a

$(OGPIO): $(CGPIO)
	$(Agcc) -c -g $(CGPIO) -o $(OGPIO)

$(OLCD): $(CLCD)
	$(Agcc) -c -g $(CLCD) -o $(OLCD)
	
$(OLED): $(CLED)
	$(Agcc) -c -g $(CLED) -o $(OLED)
	
$(ORTC): $(CRTC)
	$(Agcc) -c -g $(CRTC) -o $(ORTC)

$(OTIMER): $(CTIMER)
	$(Agcc) -c -g $(CTIMER) -o $(OTIMER)
	
$(OBUTTON): $(CBUTTON)
	$(Agcc) -c -g $(CBUTTON) -o $(OBUTTON)

libLpc:  $(OTIMER) $(ORTC) $(OGPIO)
	$(Aar) -rcs $(LIBLPC) $(OTIMER) $(ORTC) $(OGPIO)

libLcd: $(OLCD)
	$(Aar) -rcs $(LIBLCD) $(OLCD)

libLed: $(OLED)
	$(Aar) -rcs $(LIBLED) $(OLED)

libBut: $(OBUTTON)
	$(Aar) -rcs $(LIBBUTTON) $(OBUTTON)

clean:
	rm *.o *.a
	
