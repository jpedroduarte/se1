#include <stdio.h>

void Delay(unsigned int time);

void LedInit(int state); /* state=0 LED off, state != 0 LED on */
int LedGetState(void); /* retorna 0 se LED off, != 0 se LED on */
void LedSetState(int state); /* state=0 LED off,state != 0 LED on */

int main() {
	LedInit(1);
	unsigned int delay = 1000;
	while(1){
		LedSetState(1);
		Delay(delay);
		LedSetState(0);
		Delay(delay);
	}
	return 0;
}
