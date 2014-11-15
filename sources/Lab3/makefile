
insight: Lab3.axf
	arm-none-eabi-insight Lab3.axf

Lab3.axf: Delay.o initSam.o mainprog.o
	arm-none-eabi-ld Delay.o initSam.o  mainprog.o -T /home/isel/SE1/bsp/ldscript_ram libled.a -o Lab3.axf
	
Delay.o: Delay.S
	arm-none-eabi-as Delay.S -o Delay.o -g

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g
	
mainprog.o: mainprog.c
	arm-none-eabi-gcc -c -g mainprog.c -o mainprog.o
	
clean: 
	rm *.o Lab3.axf
