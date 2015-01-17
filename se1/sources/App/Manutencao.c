#include "/home/user/Desktop/host-se1/se1/includes/Manutencao.h"

static Menu m;
static initalized = 0;
static Button bUp;
static Button bDown;
static Button bOk;
static int currSubMenu;

static SubMenu subMenus[6] = {
		{"1 - Definir"    , "TMax = 000 graus"},
		{"2 - Definir"    , "TMin = 000 graus"},
		{"3 - Relogio"    , "           00-00"},
		{"4 - Calendario" , "      00-00-0000"},
		{"5 - Visualizar" , "    Temperaturas"},
		{"6 - Sair da"    , "      Manutencao"},
};

void n2str(char * str, int n, int p){
	*(str + p) = '0'+(n/10);
	*(str + p + 1) = ('0' +(n%10));
}

void putYear(char * str, int n, int p){
	*(str + p) = '0'+(n/1000);
	*(str + p +1) = '0'+((n%1000)/100);
	*(str + p + 2) = '0'+(((n%1000)%100)/10);
	*(str + p + 3) = ('0' +(n%10));
}

void Manutencao_Init(){
	if(initalized)
		return;
	m = Menu_Create(6,subMenus);
}

void Manutencao(Button bUp, Button bDown, Button bOk){
	Manutencao_Init();
	
	LCD_WriteString("MODO DE");
	LCD_Goto(1,6);
	LCD_WriteString("Manutencao");
	TMR0_Delay(3000);
	
	LCD_Clear();
	
	getSubMenu();
	
	while(1){
		if(BUTTON_getState(bUp){
			executeAction(MUP);
		}
		if(BUTTON_getState(bDown){
			executeAction(MDOWN);
		}
		if(BUTTON_getState(bOk){
			//SAIR DO MODO DE MANUTENCAO
			if(m.currSubMenu == 6)
				return;
			executeAction(MOK);
		}
	}
}

void getSubMenu(){
	char *strl1 = m.subMenus[m.currSubMenu-1].L1,
		 *strl2 = m.subMenus[m.currSubMenu-1].L2;
	LCD_WriteString(strl1);
	LCD_Goto(1,0);
	LCD_WriteString(strl2);
}

void executeAction(action a){
	if(a == MUP){
		if(Menu_IsChangeable(m,UP))
			Menu_changeSubMenu(m,UP);
	}
	if(a == MDOWN){
		if(Menu_IsChangeable(m,DOWN))
			Menu_changeSubMenu(m,DOWN);
	}
	if(a == MOK){
		entrySubMenu();
	}	
}

void ModifyValue(Val v, action a){
	if(a == MUP){
		v.curr++;
		if(v.curr > v.max)
			v.curr = v.min;
	}
	else if(a==MDOWN)[
		v.curr--;
		if(v.curr < v.min)
			v.curr = v.max;
	}
}
void IncreaseValue(Val v){
	ModifyValue(v,MUP);
}

void DecreaseValue(Val v){
	ModifyValue(v,MDOWN);
}

void WriteVal(char *n, int l, int c, int size){
	LCD_Goto(l,c);
	LCD_WriteString(n);
	LCD_Goto(l,c+size-1);
}

void entrySubMenu(){
	int s = m.currSubMenu;
	switch(s){
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			subMenu3();
			break;
		case 4:
			
			break;
		case 5:
		
			break;
		default:
			break;
	}
	
}

void subMenu3(){
	
	
}
