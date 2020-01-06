#include "string.h"
#include "stdlib.h"
#include "stdio.h"
 
int main0(){
    // init string
    // have len
    char buf1[100] = {'1','2','3','4'};
    // not len
    char buf2[] = {'a','b','c','d'};
    printf("buf1:%s\n",buf2);
    printf("buf1[80]:%d\n",buf1[80]);
    printf("Hello world\n");
    return 0;
}
 
int main1(){
    char buf3[] = "abcdefg"; // end "\0" len8

    printf("strlen(buf3):%d,sizeof(buf3):%d\n",strlen(buf3),sizeof(buf3));
    printf("Hello world!\n");
    return 0;
}
 
int main(){
    int i = 0;
    char buf4[] = "abcdefg";
    char *p = NULL;

    for (i = 0; i< strlen(buf4);i++){
        printf("buf[%d]:%c\t",i,buf4[i]);
    }
    printf("\n");

    p = buf4;
    for (i = 0;i < strlen(buf4);i++){
        printf("buf[%d]:%c\t",i,*(p+i));
    }
    printf("\n");

    for (i = 0;i < strlen(buf4);i++){
        printf("buf[%d]:%c\t",i,*(buf4+i));
    }
    printf("\n");

    // buf4[i] ==> buf4[0+i] ==> *(buf4+i)  // [] == pointer

    printf("Hello world!\n");
    return 0;
}
