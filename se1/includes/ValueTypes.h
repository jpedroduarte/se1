/** @file ValuesTypes.h
*  ValuesTypes module header.
*/
#ifndef VALUETYPES_h
#define VALUETYPES_h

/**
*
*
*/
#define TEMP 3
#define MM 2
#define YEAR 4

/**
* Estrutura que define a posição e um size
*/
typedef struct SetPos{
	int x;
	int y;
	int size;
}SetPos;

/**
* Estrutura que define os valores maximo, minimio e corrente
*/
typedef struct SetVal{
	int min;
	int max;
	int curr;
}SetVal;

/**
* Estrutura que define a posição e o valor
*/
typedef struct Seter{
	SetPos pos;
    SetVal val;
}Seter;

/**
* Coloca em str na posição p o valor n
* @param str ponteiro para onde se quer escrever
* @param n valor que se pretende escrever
* @param p posição onde se pretende escrever
*/
void n2str(char *str, int n, int p);

/**
* Formata o ano para char*
* @param str ponteiro para onde se quer escrever
* @param n ano que se pretende escrever
* @param p posição onde se pretende escrever
*/
void year2str(char *str, int n, int p);

#endif
