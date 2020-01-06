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

int main0(){
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

int GetStr0(char **p2, int *len){
    *p2 = (char *)malloc(sizeof(char) * (*len));
    if (*p2 == NULL){
        return -1;
    }

    return 0;
}


int main(){
    int len;
    char a = '0',b = '1';
    char *p1 = NULL;
    char **p2 = NULL;

    p1 = &a;   // change p1 -> a
    
    printf("p1:%s\n",p1);

    p2 = &p1;  
    *p2 = &b;   // change p1 -> b
    printf("p1:%s\n",p1);

    len = 6;
    GetStr0(&p1,&len);
    strcpy(p1, "abcdef");
    printf("p1:%s\n",p1);
    if (p1 != NULL){
        free(p1);
        p1 = NULL;
    }

    printf("Hello World!\n");
    return 0;
}
