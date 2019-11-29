#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// in in out
int StrstrWhile(char *StrBuf,char *FindStr,int *count){
    if ( StrBuf == NULL || FindStr == NULL || count == NULL){
        return -1;
    }
    char *p = StrBuf;
    char *q = FindStr;
    int TmpCount = 0;
    do{
        p = strstr(p,q);
        if (p != NULL){
            TmpCount++;
            p = p+strlen(q);
        }
        else{
            break;
        }
    }while(*p != '\0'); 
    *count = TmpCount;

    return 0;
}

int main(){
    char *p = "abcd1324b23hjkabcdhjuiasfghhabcd";  // find "abcd"
    char q[] = "abcd";
    int count = 0;
    int ret = 0;
/*    
    do{
        p = strstr(p,"abcd");
        if (p != NULL){
            count++;
            p = p+4;
        }
        else{
            break;
        }
    }while(*p != '\0'); 
    */
/*
    while( p = strstr(p,"abcd") ){
        count++;
        p = p + strlen("abcd");
        if (*p == '\0'){
            break;
        }
    }
    */
    ret = StrstrWhile(p,q,&count);
    if ( ret == -1 ){
        printf("Error ! you not gave me memory!");
    }
    
    printf("Have find %d \"abcd\" in p.",count);

    printf("Hello world\n");
    return 0;
}

