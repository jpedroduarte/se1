
insight: Lab3.axf
	arm-none-eabi-insight Log.axf

Lab3.axf: Delay.o init.o main.o /home/isel/SE1/bsp/ldscript
	arm-none-eabi-ld Delay.o -o main.o init.o -T /home/isel/SE1/bsp/ldscript
	
Delay.o: Delay.s
	arm-none-eabi-as Delay.s -o Delay.o -g

init.o: init.s
	arm-none-eabi-as init.s -o init.o -g
	
main.o: main.c
	gcc -c -g main.c -o main.o -std=c99
