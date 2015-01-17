#include "Menu.h"

#define L0 0
#define L1 1


typedef struct ManagerInfo{
	char lines[2][16];
}ManagerInfo;

typedef struct MenuInfo{
	ManagerInfo menu1;
	ManagerInfo menu2;
	ManagerInfo menu3;
	ManagerInfo menu4;
	ManagerInfo menu5;
	ManagerInfo menu6;
}MenuInfo;

MenuInfo menus = {
					{"1 - Definir    "    , "TMax = 000 graus"},
					{"2 - Definir    "    , "TMin = 000 graus"},
					{"3 - Relogio    "    , "           00-00"},
					{"4 - Calendario "    , "      00-00-0000"},
					{"5 - Visualizar "    , "    Temperaturas"},
					{"6 - Sair da    "    , "      Manutencao"}
};
MenuInfo* pMenus = &menus;

char* Manager_getStringMenu(int curr, int line);
void Manager_Print(Menu *m);
ManagerInfo* Manager_getMenu(int curr);
