#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Teacher{
    char name[20];
    int  age;
}Teacher;


int main(){
    Teacher t1;
    Teacher *p = NULL;
    int tmp = 0;

    //p-1;
    //p-2;
    tmp = (int)(&(p)->age);
    printf("%d\n",tmp);
    
    // 求结构体成员相对结构体首地址的偏移量
    // 反过来也可以用结构体任意成员地址求结构体首地址
    tmp = (int)(&((Teacher *)0)->age);
    
    printf("%d\n",tmp);

    printf("Hello world\n");
    return 0;
}

