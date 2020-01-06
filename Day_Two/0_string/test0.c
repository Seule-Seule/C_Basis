#include "string.h"
#include "stdlib.h"
#include "stdio.h"
    
int main0(){
    char *p1 = NULL;
    p1 = (char *)malloc(sizeof(char) * 100);
    if (p1 == NULL){
        return -1;
    }
    strcpy(p1,"abcdefght");
    printf("p1:%s\n",p1);
    if (p1 != NULL){
        free(p1);
        p1 = NULL; // Important!! free function not change pointer content , if not this ,it will became wild point!
    }
    if (p1 != NULL){
        free(p1);
    }

    printf("Hello world\n");
    return 0;
}

int main1(){
    char *p1 = NULL;
    // strcpy(p1,"12345"); // strcpy write data to point with momery.
    printf("Hello World!\n");
    return 0;
}


int main(){
    char *p1 = NULL;
    char *p2 = NULL;
    char buf[100];
    int i = 0,j = 0;
    p1 = &buf[0];
    p1 = &buf[2];
    strcpy(buf,"123456789");

    for (i = 0;i < 9;i++){
        p1 = &buf[i];
        printf("p1:%s\t",p1);
    }
    printf("\n");
    p2 = (char *)malloc(sizeof(char) * 100);
    strcpy(p2,"abcdefght");
    for (i = 0;i < 9;i++){
        p1 = p2 + i;
        printf("p1:%s\t",p1);
    }
    printf("\n");
    printf("Hello World!\n");
    return 0;
}



