#include <stdio.h>

void Delay(unsigned int numer, unsigned int denom);

int main() {
	LedInit(1);
	while(true){
		LedSetState(1);
		Delay(1500);
		LedSetState(0);
	}
	return 0;
}
