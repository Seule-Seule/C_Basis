#include "string.h"
#include "stdlib.h"
#include "stdio.h"

char *GetStr1(){
    char *p1 = "abcde2";
    // Temporary variable p1 address;
    printf("&p1:%d\n",&p1);
    return p1;
}

char *GetStr2(){
    char *p2 = "abcde2";
    // Temporary variable p2 address;
    printf("&p2:%d\n",&p2);
    return p2;
}
int main0(){
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = GetStr1();
    p2 = GetStr2();
    // printf p1 & p2 show memory data;
    printf("p1:%s\tP2:%s\n",p1,p2);
    // printf p1 & p2 memory address;
    printf("p1:%d\tp2:%d\n",p1,p2);
    printf("Hello world\n");
    return 0;
}

char *GetStr3(int len){
    char *p1 = NULL;
    p1 = (char *)malloc(sizeof(char)* len);
    if (p1 == NULL){
        return NULL;
    }
    return p1;
}

char *GetStr4(){
    char buf[10];
    strcpy(buf,"abshshsh");
    //  warning: function returns address of local variable!
    return buf;
}
int CheckStackTo(){
    int a;
    int b;
    printf("&a:%d\t&b:%d\n",&a,&b);
    if (b > a){
        printf("System stack up!\n");
    }
    else {
        printf("System stack down!\n");
    }
}

int main(){
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = GetStr3(10);
    if (p1 == NULL){
        return -1;
    }
    strcpy(p1,"abcdefgh");
    p2 = GetStr4();
    // printf p1 & p2 show memory data;
    printf("p1:%s\tP2:%s\n",p1,p2);
    // printf p1 & p2 memory address;
    printf("p1:%d\tp2:%d\n",p1,p2);
    CheckStackTo();
    printf("Hello world\n");
    return 0;
}

