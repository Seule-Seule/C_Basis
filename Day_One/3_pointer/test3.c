#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void main(){
	int a;
	int b;
	char *p;
	int *q;
	//p = 0xaall;
	a = 10;
	
	printf("&a:%d \n",&a); // 2127713436
	*((int *)2127713436) = 200; // it true ,but memory is change.
	*(&a)  = 300;
	q = &a;
	*q = 400;
	printf("a:%d \n",a);
	
	printf("Hello World! \n");
	return ;
}
