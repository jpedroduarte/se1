LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
LDSCRIPT = /mnt/hgfs/hostbox/se1/se1/bsp/ldscript_ram

insight: Lab7.axf
	arm-none-eabi-insight Lab7.axf

Lab7.axf: Flash.o initSam.o main.o
	arm-none-eabi-ld initSam.o Flash.o main.o -T $(LDSCRIPT) $(LIBGCC) -o Lab7.axf

Flash.o: Flash.c
	arm-none-eabi-gcc -c -g Flash.c -o Flash.o

main.o: main.c
	arm-none-eabi-gcc -c -g main.c -o main.o

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g
	
clean: 
	rm *.o *.axf
