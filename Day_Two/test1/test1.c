#include "string.h"
#include "stdlib.h"
#include "stdio.h"
int GteFileLen0(){
    int p = 0;
    p = 40;
    return p;
}

int GteFileLen1(int *p){
    if (p == NULL){
        return -1;
    }
    *p = 41;

    return 0;
}

int main(){
    int a = 10;
    int *p1 = NULL;

    a = 20;

    p1 = &a;
    *p1 = 30;
    printf("a:%d\n",a);

    a = GteFileLen0();
    printf("a:%d\n",a);

    GteFileLen1(&a);
    printf("a:%d\n",a);
    
    printf("Hello world\n");
    return 0;
}

