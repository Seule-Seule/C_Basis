#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int FreeGetMemory(char ***tmp,int *len);

int SpitStr(const char *str,char *Ctmp,char buf[10][30],int *nCount){
    char *SpStr = str;
    char *strtmp = NULL;
    char *tmp = Ctmp;
    int tmpCount = 0;
    int i = 0;
    if (str == NULL || Ctmp == NULL || buf == NULL || nCount == NULL){
        printf("str == NULL || Ctmp == NULL || buf == NULL || nCount = NULL Erro Key : -1");
        return -1;
    }

    for (i = 0;*SpStr != '\0';i++){
        strtmp = strstr(SpStr,tmp);
        tmpCount = strtmp - SpStr;
        strncpy(buf[i],SpStr,tmpCount);
        buf[i][tmpCount] = '\0';
        strtmp = strtmp+strlen(tmp);
        SpStr = strtmp;
    }
    *nCount = i;
    
    return 0;
}

int SpitStr1(const char *str,char *Ctmp,char ***buf,int *nCount){
    char *SpStr = str;
    char *strtmp = NULL;
    char *tmp = Ctmp;
    char *BufTmp = NULL;
    char **bufLine = NULL;
    char **BufLineTmp = NULL;
    int tmpCount = 0;
    int i = 0;
    int bufCount  = 0;
    int ErroMsg = 0;
    if (str == NULL || Ctmp == NULL || buf == NULL || nCount == NULL){
        printf("str == NULL || Ctmp == NULL || buf == NULL || nCount = NULL Erro Key : -1");
        ErroMsg = -1;
        goto END;
    }
    while(*SpStr != '\0'){
        SpStr = strstr(SpStr,tmp);
        bufCount++;
        SpStr = SpStr + strlen(tmp);
    }
    SpStr = str;
    bufLine = (char **)malloc(sizeof(char *) * (bufCount+1));
    memset(bufLine,0,bufCount+1);
    BufLineTmp = bufLine;
    for (i = 0;i < bufCount;i++){
        strtmp = strstr(SpStr,tmp);
        tmpCount = strtmp - SpStr;
        //strncpy(buf[i],SpStr,tmpCount);
        BufTmp = (char *)malloc(sizeof(char) * (1 + tmpCount));
        if (BufTmp == NULL){
            printf("(BufTmp == NULL) Error Key : -2");
            ErroMsg = -2;
            goto END;
        }
        strncpy(BufTmp,SpStr,tmpCount);
        *(BufTmp+tmpCount) = '\0';
        *(BufLineTmp + i) = BufTmp;
        strtmp = strtmp+strlen(tmp);
        SpStr = strtmp;
    }

END:if (ErroMsg != 0){
        ErroMsg = FreeGetMemory(&bufLine,&bufCount);
    }
    else {
        *buf = bufLine;
        *nCount = i;
    }

    return ErroMsg;
}

int FreeGetMemory(char ***tmp,int *len){
    int i = 0;
    int line = *len;
    char **str = *tmp;
    if (tmp == NULL){
        printf("(tmp == NULL) Error key: -1\n");
        return -1;
    }

    for (i = 0;i < line;i++){
        if (*(str+i) != NULL){
            free(*(str+i));
            *(str+i) == NULL;
        }
    }
    free(str);
    *tmp = NULL;
    return 0;
}

int main(){
    char *p = "aaaaa,kdivejd,kusheius,dddddd,hhhhh,";
    char *SpitC = ",";
    int count =0;
    char buf[10][30];
    char **buf1;
    int ErroMsg = 1;
    int i = 0;
    //ErroMsg = SpitStr(p,SpitC,buf,&count);
    ErroMsg = SpitStr1(p,SpitC,&buf1,&count);
    if (ErroMsg != 0){
        printf("Func SpitStr() ErroMsg key:%d\n",ErroMsg);
    }
    
    for (i = 0;i < count;i++){
        printf("'%s'\n",buf1[i]);
    }
    
    FreeGetMemory(&buf1,&count);

    printf("Hello world\n");
    return 0;
}

