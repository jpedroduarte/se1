#include "Menu.h"


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

void MENU_setCurr(Menu *m, int curr){
	m->sbm.curr = curr;
}

int MENU_getCurr(Menu *m){
	return m->sbm.curr;
}

int MENU_getFirst(Menu *m){
	return m->sbm.first;
}

int MENU_getLast(Menu *m){
	return m->sbm.last;
}
