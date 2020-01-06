#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main0(){
	int a; //I need 4 byte memory.
	int b[10]; // I need 40 byte memory.

	printf("b:%d b+1:%d &b:%d &b+1:%d \n",b,b+1,&b,&b+1);
        // b:2126222440 b+1:2126222444 &b:2126222440 &b+1:2126222480
	// b+1 &b+1 result of diffnerent. It show that b and &b data types are different.
	// b show the top of array address.
	// &b show all of array address.
	
	printf("sizeof(b):%d  sizeof(a):%d \n",sizeof(b),sizeof(a));
	printf("Hello World! \n");
	return ;
}

typedef struct ArrayTest{
	char name[4];
	int age;
}ArrayTest;  // array rename.

typedef int u4;  // variable rename.

void main(){
	int a; //I need 4 byte memory.
	int b[10]; // I need 40 byte memory.
	ArrayTest faner;
        faner.age = 20;
        printf("sizeof(u4):%d \n",sizeof(u4));	

        {
		char *p2 = NULL;
		void *p1 = NULL;
		p2 = (char *)malloc(100); // malloc memory can give everyone.
		p1 = &p2;   // void address variable can get everyone address.
		//void a; Error

	}
	printf("Hello World! \n");
	return ;
}
