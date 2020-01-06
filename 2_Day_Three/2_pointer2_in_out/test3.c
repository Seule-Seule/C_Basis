#include "string.h"
#include "stdlib.h"
#include "stdio.h"

//The secondary pointer out
int GetString(char **str1,int *len1,char **str2,int *len2){
    char *tmp = NULL;
    if (str1 == NULL || str2 == NULL){
        return -1;
    }

    tmp = (char *)malloc(100);
    if (tmp == NULL){
        return -1;
    }
    strcpy(tmp,"aabfkasdfhjagshf");
    *str1 = tmp;
    *len1 = strlen(tmp);

    tmp = (char *)malloc(100);
    if (tmp == NULL){
        return -1;
    }
    strcpy(tmp,"12342314535");
    *str2 = tmp;
    *len2 = strlen(tmp);

    return 0;
}

int GetStringFree(char **StrFree){
    char *tmp = NULL;
    if (StrFree == NULL){
        return -1;
    }
    tmp = *StrFree;
    free(tmp);
    tmp == NULL;

    return 0;
}

int main(){
    int ErroMsg = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    int len1 = 0;
    int len2 = 0;

    ErroMsg = GetString(&p1,&len1,&p2,&len2);
    if (ErroMsg != 0){
        printf("Func ErroMsg = GetString(&p1,&len1,&p2,&len2); ErroMsg key:%d\n",ErroMsg);
    }

    printf("p1:%s\nlen1:%d\np2:%s\nlen2:%d\n",p1,len1,p2,len2);

    ErroMsg = GetStringFree(&p1);
    if (ErroMsg != 0){
        printf("Func ErroMsg = GetStringFree(&p1); ErroMsg key:%d\n",ErroMsg);
    }
    ErroMsg = GetStringFree(&p2);
    if (ErroMsg != 0){
        printf("Func ErroMsg = GetStringFree(&p2); ErroMsg key:%d\n",ErroMsg);
    }



    printf("Hello world\n");
    return ErroMsg;
}

