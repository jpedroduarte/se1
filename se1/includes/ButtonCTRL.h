#ifndef BUTTONCTRL_H
#define BUTTONCTRL_H

/**
 * 
 * Estados dos butoes
 */

#include "/home/user/Desktop/host-se1/se1/includes/Button.h"

#define NONE 0
#define OKPRESSED 1
#define UPPRESSED 2
#define DOWNPRESSED 3
#define UPDOWNPRESSED 4

Button buts[3];
int tUpDown;
int evolutionState;

void BUTTONCTRL_Init(int OkPin, int UpPin, int DownPin, int timeToButtonsPressed);

int BUTTONCTRL_GetButtonsEvolution();

#endif
