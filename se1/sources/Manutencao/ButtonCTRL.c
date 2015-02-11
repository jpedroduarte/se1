#include "/home/user/Desktop/host-se1/se1/includes/ButtonCTRL.h"


void BUTTONCTRL_Init(int OkPin, int UpPin, int DownPin, int timeToButtonsPressed){	
	buts[0] = Button_Init(UpPin);    //Up Button
	buts[1] = Button_Init(DownPin);  //Down Button
	buts[2] = Button_Init(OkPin);    //OK Button
	tUpDown = timeToButtonsPressed;
	evolutionState=NONE;
}

int BUTTONCTRL_GetButtonsEvolution(){
	if(Button_PressedMoreThan(buts,tUpDown,2)){
		evolutionState = UPDOWNPRESSED;
		return UPDOWNPRESSED;
	}
	Button_getState((Button*)buts,3);
	if(buts[2].currentState == pressed){
		evolutionState = OKPRESSED;
		return OKPRESSED;
	}
	if(buts[0].currentState == pressed){
		evolutionState = UPPRESSED;
		return UPPRESSED;
	}
	if(buts[1].currentState == pressed){
		evolutionState = DOWNPRESSED;
		return DOWNPRESSED;
	}
		
	return NONE;
}

int BUTTONCTRL_RELEASE(){
	switch(evolutionState){
		case UPDOWNPRESSED:
			Button_getState((Button*)buts,2);
			if(	(buts[0].currentState == just_released || buts[0].currentState == released)
				&& (buts[1].currentState == just_released || buts[1].currentState == released)){
				evolutionState=NONE;
				return 1;
			}
			break;
		case OKPRESSED:
			Button_getState((Button*)(&buts[2]),1);
			if(	buts[2].currentState == just_released || buts[2].currentState == released){
				evolutionState=NONE;
				return 1;
			}
			break;
		case UPPRESSED:
			Button_getState((Button*)(&buts[0]),1);
			if(	buts[0].currentState == just_released || buts[0].currentState == released){
				evolutionState=NONE;
				return 1;
			}
			break;
		case DOWNPRESSED:
			Button_getState((Button*)(&buts[1]),1);
			if(	buts[1].currentState == just_released || buts[1].currentState == released){
				evolutionState=NONE;
				return 1;
			}
			break;
		default:
			break;
	}
	return 0;
}
