/** @file Menu.c
*  Menu module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/Menu.h"

/**
* Permite navegar um menu
* @param m ponteiro para um Menu
* @param op dire��o da navega��o
*/
void MENU_Navigation(Menu *m, nav n){
	int curr = MENU_getCurr(m);
	int last = MENU_getLast(m);
	int first = MENU_getFirst(m);
	if(n == OK) {
		//ENTER MENU
	}
	else {
		curr += n;
		if(curr > last)
			curr = first;
		else if(curr < first)
			curr = last;
	}
	MENU_setCurr(m,curr);
}

/**
* Altera o submenu corrente
* @param m ponteiro para um Menu
* @param curr posi��o do submenu
*/
void MENU_setCurr(Menu *m, int curr){
	m->sbm.curr = curr;
}

/**
* Retorna a posi��o do submenu corrente
* @param m ponteiro para um Menu
*/
int MENU_getCurr(Menu *m){
	return m->sbm.curr;
}

/**
* Returna a posi��o do primeiro submenu
* @param m ponteiro para um Menu
*/
int MENU_getFirst(Menu *m){
	return m->sbm.first;
}

/**
* Returna a posi��o do ultimo submenu
* @param m ponteiro para um Menu
*/
int MENU_getLast(Menu *m){
	return m->sbm.last;
}
