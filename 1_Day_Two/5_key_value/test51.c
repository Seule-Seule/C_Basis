#include "string.h"
#include "stdlib.h"
#include "stdio.h"
// 一个字符串，将下标为偶数的字符合并成一个新的字符串A，再将下标为奇数的字符提出合并成一个新的字符串B

int GetParityStr(char *InStr,char *OutStr1,char *OutStr2){
    char *In = InStr;
    char *str1 = OutStr1;
    char *str2 = OutStr2;
    int tmp = 0,i = 0,j =0 ;
    if (InStr == NULL || OutStr2 == NULL || OutStr1 == NULL){
        printf("Instr == NULL || OutStr2 == NULL || OutStr1 == NULL ? ");
        return -1;
    }
    for (tmp = 0;tmp < strlen(In);tmp++){
        if((tmp % 2) == 0){
            *(str2+i++) = *(In+tmp);
        }
        else {
            *(str1+j++) = *(In+tmp);
        }
    }
    *(str2+i) = '\0';
    *(str1+j) = '\0';

    return 0;
}

int main(){
    char *p = "hjkashdfjklashfjklasfhlaks";
    char buf1[100];
    char buf2[100];
    int ret = 0;

    ret = GetParityStr(p,buf1,buf2);
    if (ret != 0){
        printf("Error! GetParityStr() ");
    }
    printf("p:%s\t%d\n",p,strlen(p));
    printf("str1:%s\t%d\n",buf1,strlen(buf1));
    printf("str2:%s\t%d\n",buf2,strlen(buf2));
    printf("Hello world\n");
    return 0;
}

