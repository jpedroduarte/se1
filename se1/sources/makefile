#root Path
rootPath = /home/user/Desktop/host-se1/se1
#includes Path
incPath = $(rootPath)/includes
#libraries Path
libsPath = $(rootPath)/libs
#sources Path
srcPath = $(rootPath)sources/

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

#LIBS
lpc = lpc2106
lcd = lcd
led = led

LIBLPC = lib$(lpc).a
LIBLCD = lib$(lcd).a
LIBLED = lib$(led).a

ILIBLPC = -L$(libsPath) -l$(lpc)
ILIBLCD = -L$(libsPath) -l$(lcd)
ILIBLED = -L$(libsPath) -l$(led)

IALLLIBS = $(ILIBLCD) $(ILIBLED) $(ILIBLPC)

####
