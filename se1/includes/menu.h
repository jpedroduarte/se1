#ifndef MENU_H
#define MENU_H

typedef struct SubMenu{
	char *L1;
	char *L2;
}SubMenu;

typedef struct menu{
	int totalSubMenu;
	int currSubMenu;
	SubMenu subMenus[];
} Menu;

typedef enum {UP=1,DOWN=-1, OK = 0} SubMenuNav;

Menu Menu_Create(int totalSubMenu, SubMenu subMenus[]);
void Menu_changeSubMenu(Menu m, SubMenuNav s);
int Menu_IsChangeable(Menu m, SubMenuNav s);

#endif
