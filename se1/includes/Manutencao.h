#ifndef MANUTENCAO_H
#define MANUTENCAO_H

#include "/home/user/Desktop/host-se1/se1/includes/menu.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/button.h"
#include <string.h>

typedef struct Pos{
	int x;
	int y;
} Pos;

typedef struct Val{
	int curr;
	int min;
	int max;
} Val;

void WriteVal(Val v, Pos p);

typedef enum buttonActions{
	MUP,
	MDOWN,
	MOK
} action;

void ModifyValue(Val v, action a);
void IncreaseValue(Val v);
void DecreaseValue(Val v);

void Manutencao_Init();
void Manutencao(Button bUp, Button bDown, Button bOk);
void executeAction(action a);

void entrySubMenu();
#endif
