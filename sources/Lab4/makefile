
insight: Lab4.axf
	arm-none-eabi-insight Lab4.axf

Lab4.axf: keyboard.o initSam.o led.o
	arm-none-eabi-ld keyboard.o initSam.o led.o -T /home/isel/SE1/bsp/ldscript_ram -o Lab4.axf

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g

keyboard.o: keyboard.c
	arm-none-eabi-gcc -c -g keyboard.c -o keyboard.o
	
led.o: led.c
	arm-none-eabi-gcc -c -g led.c -o led.o
	
clean: 
	rm *.o Lab4.axf
