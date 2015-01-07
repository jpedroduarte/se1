
insight: Lab6.axf
	arm-none-eabi-insight Lab6.axf

Lab6.axf: lcd.o main.o initSam.o gpio.o
	arm-none-eabi-ld lcd.o main.o initSam.o gpio.o -T /home/user/Desktop/host-se1/se1/bsp/ldscript_ram -o Lab6.axf

gpio.o: gpio.c
	arm-none-eabi-gcc -c -g gpio.c -o gpio.o

lcd.o: lcd.c
	arm-none-eabi-gcc -c -g lcd.c -o lcd.o

main.o: main.c
	arm-none-eabi-gcc -c -g main.c -o main.o

initSam.o: initSam.S
	arm-none-eabi-as initSam.S -o initSam.o -g
	
clean: 
	rm *.o *.axf
