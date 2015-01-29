/** @file Menu.h
*  Menu module header.
*/
#ifndef MENU_H
#define MENU_H

/**
* Define um subMenu
*/
typedef struct navSubMenu{
	int curr;
	int first;
	int last;
}navSubMenu;

/**
* Define a dire��o de navega��o
*/
typedef enum nav{
	UP = 1,
	DOWN = -1,
	OK = 0
} nav; 

/**
* Define um Menu
*/
typedef struct Menu{
	navSubMenu sbm;
} Menu;

/**
* Altera o submenu corrente
* @param m ponteiro para um Menu
* @param curr posi��o do submenu
*/
void MENU_setCurr(Menu *m, int curr);

/**
* Retorna a posi��o do submenu corrente
* @param m ponteiro para um Menu
*/
int MENU_getCurr(Menu *m);

/**
* Returna a posi��o do primeiro submenu
* @param m ponteiro para um Menu
*/
int MENU_getFirst(Menu *m);

/**
* Returna a posi��o do ultimo submenu 
* @param m ponteiro para um Menu
*/
int MENU_getLast(Menu *m);

/**
* Permite navegar um menu
* @param m ponteiro para um Menu
* @param op dire��o da navega��o
*/
void MENU_Navigation(Menu *m, nav op);

#endif
