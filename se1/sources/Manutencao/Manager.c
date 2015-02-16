#include <stdio.h>
#include <stdlib.h>

#include "/home/user/Desktop/host-se1/se1/includes/Manager.h"

static int currMenu;

void Manager_Print(Menu *m){
	int curr = MENU_getCurr(m) -1;
	LCD_Clear();
	LCD_WriteString(Manager_getStringMenu(curr,L0));
	LCD_Goto(1,0);
	LCD_WriteString(Manager_getStringMenu(curr,L1));
}

char* Manager_getStringMenu(int curr, int line){
	ManagerInfo* ptr = Manager_getMenu(curr);
	return ptr->lines[line];
}

ManagerInfo* Manager_getMenu(int curr){
	return ((ManagerInfo*)pMenus)+curr;
}


//REMOVER buts e nButs
//USAR BUTTONCTRL
int Manager_Entry(Menu *m, Button *buts, int nButs, RegsLog *pRegLog){
	currMenu = MENU_getCurr(m) -1;
	int curr = MENU_getCurr(m)-1;
	ManagerInfo* ptr = Manager_getMenu(curr);
	EntryMode *e = &(ptr->enter);
	e->on = 1;
	Manager_Enter(e, buts, nButs,pRegLog);
	if(e->mType != EXIT){
		Manager_Print(m);
		return 0; //CONTINUE IN MANAGER
	}
	return 1; //EXIT MANAGER
}

void Manager_Enter(EntryMode *e, Button *buts, int nButs, RegsLog *pRegLog){
	ManType mT = e->mType;
	int x = 0, y=0;
	switch(mT){
		case SET:
			Manager_Setting((Seter*)(&(e->vals)),e->seterSize, buts, nButs);
			break;
		case LOG:
			LCD_Clear();
			Manager_LogMode(pRegLog,buts,nButs);
			
			
			TMR0_Delay(5000);
			break;
		case EXIT:
			LCD_Clear();
			LCD_WriteString("EXIT");
			TMR0_Delay(5000);
			break;
		default:
			break;
	}
}

void temp2str(char *str, int n, int p){
	THERM_convertTemperature(str,p-1,THERM_Temp2short(n));
}

int Manager_EntryGetX(Seter e){
	return e.pos.x;
}
int Manager_EntryGetY(Seter e){
	return e.pos.y;
}

void getXY(Seter e, int *x , int *y){
	*(x) = Manager_EntryGetX(e);
	*(y) = Manager_EntryGetY(e);
}
void MoveCursor(Seter e, int *x , int *y){
	getXY(e,x , y);
	
	LCD_Goto(*x,*y);
}

void putVal(char *str, int val, int size, int pos){
	switch(size){
		case MM:
			n2str(str,val,pos);
			break;
		case TEMP:
			temp2str(str,val,pos);
			break;
		case YEAR:
			year2str(str,val,pos);
			break;
		default:
			break;
	}
}

void updateVal(SetVal *vals,int x ,int y, int size, int op, int valSet){
	int curr = (vals->curr) + op;
	int min = vals->min;
	int max = vals->max;
	if(curr > max)
		curr = min;
	else if(curr < min)
		curr = max;
	vals->curr = curr;
	char s[size+1];
	char *str = s;
	putVal(str,curr,size,0);
	*(str+size) = '\0';
	int auxY = (y-(size-1));
	LCD_Goto(x,auxY);
	LCD_WriteString(str);
	LCD_Goto(x,y);
	ManagerInfo *mInfo = (((ManagerInfo*)(pMenus)) + currMenu);
	char *arr = (char*)(&(mInfo->lines[x]));
	putVal(arr,curr,size,auxY);
	
	
}

//Buts {ok,up,down}
void Manager_Setting(Seter *s, int seterSize, Button *buts, int nButs){
	SetVal *vals = &(s->val);
	SetPos *pos = &(s->pos);
	int x, y;
	MoveCursor(*s,&x,&y);
	int i = 0;
	while(i < seterSize){
		Button_getState(buts, 3);
		if(buts->currentState == just_pressed){
			i++;
			if(i == seterSize)
				break;
			s++;			
			MoveCursor(*s,&x,&y);
			vals = &(s->val);
			pos = &(s->pos);
			while(1){
				Button_getState(buts,1);
				if((buts)->currentState == just_released)
					break;
			}
		}
		if((buts+1)->currentState == just_pressed){
			getXY(*s,&x ,&y);
			updateVal(vals,x,y, s->pos.size, INC, i);
			while(1){
				
				Button_getState(buts+1,1);
				if((buts+1)->currentState == just_released || (buts+1)->currentState == released)
					break;
			}
		}
		if((buts+2)->currentState == just_pressed ){
			getXY(*s,&x ,&y);
			updateVal(vals,x,y, s->pos.size, DEC, i);
			while(1){
				Button_getState(buts+2,1);
				if((buts+2)->currentState == just_released)
					break;
			}
			
		}
	}
}

void Manager_LogMode(RegsLog *pRegLog, Button *buts, int nButs){
	if(pRegLog->currSize ==0){
		LCD_Clear();
		LCD_WriteString("Regist Empty");
		TMR0_Delay(2000);
		return;
	}
		
	while(1){
		Button_getState(buts, 3);
		if(buts->currentState == just_pressed){
			while(1){
				Button_getState(buts+1,1);
					if((buts+1)->currentState == just_released)
						return;
			}
		}
		if((buts+1)->currentState == just_pressed){
			while(1){
				Button_getState(buts+1,1);
				if((buts+1)->currentState == just_released || (buts+1)->currentState == released){
					LOG_ShowNext();
					break;
				}
			}
		}
		if((buts+2)->currentState == just_pressed ){
			//DOWN LOG
			
		}
	}
	
}
