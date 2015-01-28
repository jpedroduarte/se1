#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"

void n2str(char *str, int n, int p){
	*(str + p) = '0'+(n/10);
	*(str + p + 1) = ('0' +(n%10));
}

void year2str(char *str, int n, int p){
	*(str + p) = '0'+(n/1000);
	*(str + p +1) = '0'+((n%1000)/100);
	*(str + p + 2) = '0'+(((n%1000)%100)/10);
	*(str + p + 3) = ('0' +(n%10));
}
