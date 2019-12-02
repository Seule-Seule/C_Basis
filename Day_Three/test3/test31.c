#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// The secondary pointer in
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
            if (strcmp(*(SecondPointer+i),*(SecondPointer+j)) > 0){
                tmp = *(SecondPointer+i);
                *(SecondPointer+i) = *(SecondPointer+j);
                *(SecondPointer+j) = tmp;
            }
        }
    }

    return 0;
}

int main(){
    int ErroMsg = 0;
    char **p2 = NULL;
    char *array[] = {"8","aaaaaa","cccccc","dddddddd","22222222222","11"};
    int i = 0,j = 0;
    int len;
    len = sizeof(array)/sizeof(*(array+1));

    printf("Before Sort:\n");
    ErroMsg = PrintSecondaryPointer(array,&len);
    if (ErroMsg != 0 ){
        printf("Func ErroMsg = PrintSecondaryPointer(array,&len); ErroMsg key:%d\n",ErroMsg);
    }

    ErroMsg = SortSecondPointer(array,&len);
    if (ErroMsg != 0){
        printf("Func  ErroMsg = SortSecondPointer(array,&len); ErroMsg key:%d\n",ErroMsg);
    }

    printf("\nEnd sort:\n");
    ErroMsg = PrintSecondaryPointer(array,&len);
    if (ErroMsg != 0 ){
        printf("Func ErroMsg = PrintSecondaryPointer(array,&len); ErroMsg key:%d\n",ErroMsg);
    }

    printf("Hello world\n");
    return ErroMsg;
}
