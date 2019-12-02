#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// The secondary pointer in 2
int PrintfSecondPointer(char array[10][30],int *num){
    int i = 0;
    
    for (i = 0;i < *num;i++){
        printf("\t%s\n",array[i]);
    }

    return 0;
}

int SortSecondPointer(char array[10][30],int *num){
    int i = 0,j = 0;
    int len = *num;
    char tmp[30];
    for (i = 0;i < len;i++){
        for (j = i;j < len;j++){
            if (strcmp(array[i],array[j]) > 0){
                strcpy(tmp,array[i]);
                strcpy(array[i],array[j]);
                strcpy(array[j],tmp);
            }
        }
    }

    return 0;
}

int main(){
    char buf[10][30] = {"111111","dddddd","33","ffffff","00000","dddddd"};
    int len = 6;
    
    printf("Before sort:\n");
    PrintfSecondPointer(buf,&len);

    SortSecondPointer(buf,&len);

    printf("\nEnd sort:\n");
    PrintfSecondPointer(buf,&len);

    printf("Hello world\n");
    return 0;
}

