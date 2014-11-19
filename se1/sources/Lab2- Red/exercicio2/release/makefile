
insight: Log.axf
	arm-none-eabi-insight Log.axf

Log.axf: Log.o ex1.o init.o main.o
	arm-none-eabi-ld ex1.o Log.o -o main.o init.o Log.o
	
Log.o: Log.s
	arm-none-eabi-as Log.s -o Log.o -g
	
ex1.o: /home/isel/SE1/sources/Lab2/exercicio1/release/ex1.s
	arm-none-eabi-as /home/isel/SE1/sources/Lab2/exercicio1/release/ex1.s -o ex1.o -g

init.o: init.s
	arm-none-eabi-as init.s -o init.o -g
	
main.o: main.c
	gcc -c -g main.c -o main.o -std=c99
