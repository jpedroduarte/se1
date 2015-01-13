
typedef struct menu{
	int totalSubMenu;
	int currSubMenu;
} Menu;

typedef enum {UP,DOWN} SubMenuNav;

Menu Menu_Create(int totalSubMenu){
	Menu m = {0};
	m.totalSubMenu = totalSubMenu;
	m.currSubMenu = 1;
	return m;
}

Menu Menu_changeSubMenu(Menu m, SubMenuNav s){
	int res = 0;
	if(s == UP){
		m.currSubMenu +=1;
		return m;
	}
	else if(s==DOWN){
		m.currSubMenu -=1;
		return m;
	}
	return m;
}

int Menu_IsChangeable(Menu m, SubMenuNav s){
	if(s == UP){
		if(m.currSubMenu < m.totalSubMenu){
			return 1;
		}
	}
	else if(s==DOWN){
		if(m.currSubMenu > 1){
			return 1;
		}
	}
	return 0;
}
