#include "/home/user/Desktop/host-se1/se1/includes/menu.h"

Menu Menu_Create(int totalSubMenu, subMenu sMenus[]){
	Menu m = {0};
	m.totalSubMenu = totalSubMenu;
	m.currSubMenu = 1;
	m.subMenus = sMenus;
	return m;
}

void Menu_changeSubMenu(Menu m, SubMenuNav s){
	if(UP)
		m.currSubMenu +=1;
	else
		m.currSubMenu -=1;
}

int Menu_IsChangeable(Menu m, SubMenuNav s){
	if(UP){
		if(m.currSubMenu < m.totalSubMenu){
			return 1;
		}
	}
	else{
		if(m.currSubMenu > 1){
			return 1;
		}
	}
	return 0;
}

