
insight: Log.axf
	arm-none-eabi-insight Log.axf

Log.axf: Log.o Div.o init.o main.o
	arm-none-eabi-ld Div.o Log.o -o main.o init.o Log.o
	
Log.o: Log.s
	arm-none-eabi-as Log.s -o Log.o -g
	
Div.o: Div.s
	arm-none-eabi-as Div.s -o Div.o -g

init.o: init.s
	arm-none-eabi-as init.s -o init.o -g
	
main.o: main.c
	gcc -c -g main.c -o main.o -std=c99
