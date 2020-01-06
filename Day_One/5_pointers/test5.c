#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main0(){
    int a = 10;
    int *p = NULL; // 4 byte in memory.
    char **p2 = NULL;
    printf("sizeof(a:%d\tp:%d\tp2:%d\t)\n",sizeof(a),sizeof(p),sizeof(p2));
    
    p = &a;
    *p = 100;  
    {
        int c = 0;
        c = *p;
    }
    {
        char *p4 = NULL;
        p4 = (char *)malloc(sizeof(char) * 10);
    }

    printf("Hello world\n");
    return 0;
}

char *GetStr(){
    int i = 0;
    char *p = NULL;
    p = "abc";
    return p;
}

int Getabc1(char *p);
int Getabc2(char **p);
int Getabc3(char ***p);
int Getabc4(char (*p[]));
int Getabc5(char p[10][20]);

int main(){
    char *p  =NULL;
    p = GetStr();
    printf("p:%s\n",p);

    // memory  Segmentation fault (ignored) ;
    // *(p+2) = "r";

    printf("Hello World\n");
    return 0;
}
