#ifndef MANAGER_H_
#define MANAGER_H_

#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "Menu.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/Button.h"


#define L0 0
#define L1 1

typedef enum managementType{
	SET,
	LOG,
	EXIT
}ManType;

typedef struct entryMode{
	int on;
	Seter vals[3];
	int seterSize;
	ManType mType;
}EntryMode;

typedef struct ManagerInfo{
	char lines[2][16];
	EntryMode enter;
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
		/** MENU 1 
		 * 
		 * Definir o valor de tmax
		 * 
		 * */
		{"1 - Definir    "    , "TMax = 000 graus" , {0, {{1, 9,2}} , 1, SET} },
		/** MENU 2 
		 * 
		 *  Definir o valor de tmin 
		 * 
		 * */
		{"2 - Definir    "    , "TMin = 000 graus" , {0, {{1, 9,2}} , 1, SET} },
		/** MENU 3 
		 * 
		 * Acertar o relógio
		 *  HH-MM
		 * 
		 *         Min - Max
		 *  HH       0 -  23
		 *  MM       0 -  59
		 * */
		{"3 - Relogio    "    , "           00-00" , {0, {{1,12,2}, {1,15,2}} , 2,SET} },
		/** MENU 4 
		 * 
		 *  Acertar o calendário
		 *  
		 *  DD-MM-AAAA
		 *         Min - Max
		 *  DD       1 -  31
		 *  MM       1 -  12
		 *  AAAA  2014 - X
		 * */
		{"4 - Calendario "    , "      00-00-0000" , {0, {{1, 7,2},{1,10,2},{1,15,2}} , 3, SET} },
		/** MENU 5 
		 * 
		 *  Visualizar o registo de temperaturas
		 * 
		 * */
		{"5 - Visualizar "    , "    Temperaturas" , {0, {0} , LOG} },
		/** MENU 6 *
		 * 
		 *  Sair da Manutencao
		 * 
		 */
		{"6 - Sair da    "    , "      Manutencao" , {0, {0} , EXIT} }
};
MenuInfo* pMenus = &menus;

char* Manager_getStringMenu(int curr, int line);
void Manager_Print(Menu *m);
ManagerInfo* Manager_getMenu(int curr);

int Manager_Entry(Menu *m, Button *buts, int nButs);

void Manager_Enter(EntryMode *e, Button *buts, int nButs);

/**
 * SET MODE
 * */
void Manager_SetMode(EntryMode e);
/**
 *	GET POS -> (x,y)
 *  GET/SET VAL -> curr up/down
 *  MOVENEXTVAL 
 *  
 *  GET/SET VALUES <-> FLASH
 * 
 **/
int Manager_EntryGetX(Seter e);
int Manager_EntryGetY(Seter e);


/**
 * LOG MODE
 * */
void Manager_LogMode(EntryMode e);
//void Manager_ExitMode(EntryMode e);

void Manager_Setting(Seter *s, int seterSize, Button *buts, int nButs);
#endif
