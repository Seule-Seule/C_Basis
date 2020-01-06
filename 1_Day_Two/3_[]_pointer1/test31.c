#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int StrPrintf(char *StrAddr){
    if (StrAddr == NULL){
        return -1;
    }
    printf("\n%s\n",StrAddr);
    return 0;
}

int main0(){
    char a[] = "i am a bistu.";
    char buf[64];
    int i = 0;
    // copy string
    for (i = 0;*(a+i)!='\0';i++){
        *(buf+i) = *(a+i);
    }
    buf[i] = '\0';

    StrPrintf(a);
    StrPrintf(buf);

    printf("Hello world\n");
    return 0;
}


int CopyStr(char *str1,char *str2){
    if (str1 == NULL || str2 == NULL){
        return -1;
    }
//    for (;*str1 != '\0';str1++,str2++){
//        *str2=*str1;
//    }
//  *str2='\0';
    
//    for (;*str1='\0';){
//        *str1++ = *str2++;
//    }
//    *str2='\0';

//    while( (*str2 = *str1) != '\0'){
//        *str2++;
//        *str1++;
//    }

//    while( (*str2++ = *str1++) != '\0');

    while( (*str2++ = *str1++));

    return 0;
}

int main(){
    int ret = 0;
    char *p = "abasjlhkdfuasdjlghflZ";
    char b[64];
    ret = CopyStr(p,b);
    if (ret == -1){
        printf("String copy error !!");
    }
    StrPrintf(p);
    StrPrintf(b);

    return 0;
}

