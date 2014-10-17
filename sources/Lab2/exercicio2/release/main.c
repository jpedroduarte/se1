#include <stdio.h>
#include <stdbool.h>

extern unsigned __bss_start__[];
extern unsigned __bss_end__[];
typedef void (*funcPtr)();
extern funcPtr __ctor_list__[];
extern funcPtr __ctor_end__[];

extern void crt_init(){
	for(unsigned *p=__bss_start__; p!=__bss_end__; ++p)
		*p = 0;
	for(funcPtr *p=__ctor_list__; p!=__ctor_end__; ++p)
		(*p)();
}

unsigned int Div(unsigned int numer, unsigned int denom);
int Log(unsigned int* result, unsigned int value, unsigned char base);

bool test_normal_value() {
	int p=0;
	int res= Log(&p, 9, 3);
	printf("Log %u base %u = %u;\n",9,3,p);
	return res==0 && p==2;
}

bool test_normal_value1() {
	int p=0;
	int res= Log(&p, 10000, 10);
	printf("Log %u base %u = %u;\n",1000,10,p);
	return res==0 && p==4;
}

bool test_irracional_value() {
	int p=0;
	int res= Log(&p, 7, 3);
	printf("Log %u base %u = %u;\n",7,3,p);
	return res==0 && p==1;
}

bool test_negative_value() {
	int p=0;
	int res= Log(&p, -1, 10);
	printf("Log %u base %u = %u;\n",-1,10,p);
	return res==-1;
}

bool test_negative_base() {
	int p=0;
	int res= Log(&p, 10, -1);
	printf("Log %u base %u = %u;\n",10,-1,p);
	return res==-1;
}

bool test_base_equal1() {
	int p=0;
	int res= Log(&p, 10, 1);
	printf("Log %u base %u = %u;\n",10,1,p);
	return res==-1;
}

int main() {
	if (test_normal_value() &&
	  test_normal_value1 &&
	  test_irracional_value() &&
	  test_negative_value() &&
	  test_negative_base() &&
	  test_base_equal1()
	  ) {
			printf("Sucessfull!\n");
			return 0;	
	}
	
	printf("At least one test has failed.\n");
	return 1;
}
