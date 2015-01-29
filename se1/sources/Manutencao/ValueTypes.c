/** @file ValuesTypes.c
*  ValuesTypes module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"

/**
* Coloca em str na posição p o valor n
* @param str ponteiro para onde se quer escrever
* @param n valor que se pretende escrever
* @param p posição onde se pretende escrever
*/
void n2str(char *str, int n, int p){
	*(str + p) = '0'+(n/10);
	*(str + p + 1) = ('0' +(n%10));
}

/**
* Formata o ano para char*
* @param str ponteiro para onde se quer escrever
* @param n ano que se pretende escrever
* @param p posição onde se pretende escrever
*/
void year2str(char *str, int n, int p){
	*(str + p) = '0'+(n/1000);
	*(str + p +1) = '0'+((n%1000)/100);
	*(str + p + 2) = '0'+(((n%1000)%100)/10);
	*(str + p + 3) = ('0' +(n%10));
}
