#ifndef keyboard.h
#define keyboard.h

void KBD_Init(unsigned int layout[16]);

int KBD_Hit(void);

int KBD_Read(int state);

#endif 
