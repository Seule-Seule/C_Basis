#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// 有一个字符串开头或结尾含有n个空格( a b c d ),欲去掉前后中空格，返回一个新字符串

int RmSpace(char *InStr,char *OutStr){
    char *In = InStr;
    char *Out = OutStr;
    char *tmp = NULL;
    int len = 0;
    if (In == NULL || Out == NULL){
        printf("Get error memory address!");
        return -1;
    }
    while(*In == ' '){
        tmp = ++In;
    }
    strcpy(Out,tmp);
    len = strlen(Out) - 1;
    while(*(Out+len) == ' '){
        *(Out+len--) = '\0';
    }

    return 0;
}

int main(){
    char *p = "    sab  llcdjsf  hjasdfh  j   ";
    char buf[64];
    int ret = 0;
    
    ret = RmSpace(p,buf);
    if (ret != 0){
        printf("Error! RmSpace() not go as tought!");
    }
    printf("Before:'%s'\n",p);
    printf("After:'%s'\n",buf);
    printf("Hello world\n");
    return 0;
}

