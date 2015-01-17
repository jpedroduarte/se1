#ifndef MENU_H
#define MENU_H

typedef struct navSubMenu{
	int curr;
	int first;
	int last;
}navSubMenu;

typedef enum nav{
	UP = 1,
	DOWN = -1,
	OK = 0
} nav; 

typedef struct Menu{
	navSubMenu sbm;
} Menu;

void MENU_setCurr(Menu *m, int curr);
int MENU_getCurr(Menu *m);

int MENU_getFirst(Menu *m);
int MENU_getLast(Menu *m);

void MENU_Navigation(Menu *m, nav op);

#endif
