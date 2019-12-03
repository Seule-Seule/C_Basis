#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main0(){
    char **p = NULL;
    int i = 0,j = 0;
    int line = 5;
    int col = 100;
    char *tmp = NULL;
    char tmpBuf[100];
    // Get memory .
    p = (char **)malloc(sizeof(char *) * line);
    for (i = 0;i < line;i++){
        *(p+i) = (char *)malloc(sizeof(char) * col);
        sprintf(*(p+i),"%d%d%d%d%d",i+1,i+1,i+1,i+1,i+1);
    }
    
    // Printf str.
    printf("Before sort:\n"); 
    for (i = 0;i < line;i++){
        printf("\t%s\n",*(p+i));
    }

    /*
    // sort
    for (i = 0;i < line;i++){
        for (j=i+1;j < line;j++){
            if (strcmp(*(p+i),*(p+j)) < 0){
                tmp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = tmp;
            }
        }
    }
    */
    for (i = 0;i < line;i++){
        for (j=i+1;j < line;j++){
            if (strcmp(*(p+i),*(p+j)) < 0){
                strcpy(tmpBuf,*(p+i));
                strcpy(*(p+i),*(p+j));
                strcpy(*(p+j),tmpBuf);
            }
        }
    }

    // Printf str.
    printf("After sort:\n");
    for (i = 0;i < line;i++){
        printf("\t%s\n",*(p+i));
    }

    // Free memory.
    for (i = 0;i < line;i++){
        if (*(p+i) == NULL){
            return -1;
        }
        free(*(p+i));
        *(p+i) == NULL;
    }
    if ( p == NULL){
        return -1;
    }
    free(p);
    p = NULL;

    printf("Hello world\n");
    return 0;
}

int PrintSecondaryPointer(char  **SecondPointer,int *len){
    int num = *len,i = 0;
    if (SecondPointer == NULL){
        printf("SecondPointer == NULL in int PrintSecondaryPointer(char  **SecondPointer,int *len)!\n");
        return -1;
    }
    for (i = 0;i < num;i++){
        printf("\t%s\n",*(SecondPointer+i));
    }
    return 0;
}

int SortSecondPointer(char **SecondPointer,int *len){
    int i = 0,j = 0;
    int num = *len;
    char *tmp;
    if (SecondPointer == NULL){
        printf("(SecondPointer == NULL) in int SortSecondPointer(char **SecondPointer,int *len)!\n");
        return -1;
    }
    for (i = 0;i < num;i++){
        for (j = i;j < num;j++){
            if (strcmp(*(SecondPointer+i),*(SecondPointer+j)) < 0){
                tmp = *(SecondPointer+i);
                *(SecondPointer+i) = *(SecondPointer+j);
                *(SecondPointer+j) = tmp;
            }
        }
    }

    return 0;
}

int GetMemory(char ***str,int *line,int *col){
    char **p = NULL;
    int i = 0;
    int hang = *line;
    int lie = *col;
    p = (char **)malloc(sizeof(char *) * hang);
    if (p == NULL){
        printf("(p == NULL) in GetMemory(char ***str,int *line,int *col) Erro key : -1");
        return -1;
    }
    for (i = 0;i < hang;i++){
        *(p+i) = (char *)malloc(sizeof(char) * lie);
        if ( *(p+i) == NULL){
            printf("( *(p+i) == NULL) in *(p+i) = (char *)malloc(sizeof(char) * lie) Erro key : -2");
            return -2;
        }
        sprintf(*(p+i),"%d%d%d%d%d",i+1,i+1,i+1,i+1,i+1);
    }
    *str = p;

    return 0;
}

int FreeGetMemory(char **str,int *len){
    int i = 0;
    int line = *len;
    if (str == NULL){
        printf("(str == NULL) Error key: -1\n");
        return -1;
    }

    for (i = 0;i < line;i++){
        if (*(str+i) == NULL){
            return -1;
        }
        free(*(str+i));
        *(str+i) == NULL;
    }
    free(str);

    return 0;
}

int main(){
    char **p = NULL;
    int line = 5;
    int col = 100;
    int ErroMsg = 0;

    // Get memory.
    ErroMsg = GetMemory(&p,&line,&col);
    if (ErroMsg != 0){
        printf("Func ErroMsg = GetMemory(&p,&line,&col) ErroMsg key:%d\n",ErroMsg);
    }

    // Printf str.
    printf("Before sort:\n"); 
    ErroMsg = PrintSecondaryPointer(p,&line);
    if (ErroMsg != 0){
        printf("Func ErroMsg = PrintSecondaryPointer(p,line) ErroMsg key:%d\n",ErroMsg);
    }

    // sort
    ErroMsg = SortSecondPointer(p,&line);
    if (ErroMsg != 0){
        printf("Func ErroMsg = SortSecondPointer(p,&line) ErroMsg key:%d\n",ErroMsg);
    }
    // Printf str.
    printf("After sort:\n"); 
    ErroMsg = PrintSecondaryPointer(p,&line);
    if (ErroMsg != 0){
        printf("Func ErroMsg = PrintSecondaryPointer(p,line) ErroMsg key:%d\n",ErroMsg);
    }
    
    // Free memory
    ErroMsg = FreeGetMemory(p,&line);
    if (ErroMsg != 0){
        printf("Func ErroMsg = FreeGetMemory(p,&line) ErroMsg key:%d\n",ErroMsg);
    }
    p = NULL;

    printf("Hello world\n");
    return 0;
}

