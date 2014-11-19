
insight: Lab4.axf
	arm-none-eabi-insight Lab4.axf

Lab4.axf: Delay.o main.o keyboard.o initSam.o led.o
	arm-none-eabi-ld Delay.o main.o keyboard.o initSam.o led.o -T /home/user/Desktop/host-se1/se1/bsp/ldscript_ram -o Lab4.axf

keyboard.o: keyboard.c
	arm-none-eabi-gcc -c -g keyboard.c -o keyboard.o
	
led.o: led.c
	arm-none-eabi-gcc -c -g led.c -o led.o

Delay.o: Delay.S
	arm-none-eabi-as Delay.S -o Delay.o -g

main.o: main.c
	arm-none-eabi-gcc -c -g main.c -o main.o

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g
	
clean: 
	rm *.o Lab4.axf
