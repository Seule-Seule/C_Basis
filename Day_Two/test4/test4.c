#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int StrstrWhile(char *StrBuf,char *FindStr,int *count){
    char *p = StrBuf;
    char *q = FindStr;
    do{
        p = strstr(p,q);
        if (p != NULL){
            *count++;
            p = p+4;
        }
        else{
            *count = 0;
            break;
        }
    }while(*p != '\0'); 

    return 0;
}




 
int main(){
    char *p = "abcd1324b23hjkabcdhjuiasfghhabcd";  // find "abcd"
    char q[4] = "abcd";
    int count = 0;
//*    
    do{
        p = strstr(p,"abcd");
        if (p != NULL){
            count++;
            p = p+4;
        }
        else{
            count = 0;
            break;
        }
    }while(*p != '\0'); 
    //*/

    //StrstrWhile(p,q,&count);
    printf("Have find %d \"abcd\" in p.",count);

    printf("Hello world\n");
    return 0;
}

