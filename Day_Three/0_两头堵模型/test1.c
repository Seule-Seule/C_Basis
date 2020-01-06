#include "string.h"
#include "stdlib.h"
#include "stdio.h"


// 两头堵模型
int RemoveSpace(const char *StrIn,char *StrOut){
    int ErroMsg = 0;
    int i = 0,j = 0;
    int index = 0;
    if (StrOut == NULL || StrIn == NULL){
        ErroMsg = -1;
        printf("StrOut == NULL || strIn == NULL Erro msg key:%d\n",ErroMsg);
        return ErroMsg;
    }
    //注意：pin[i]==" "这么写是错误的，" "是字符串(2个字符，'\0'也算一个)，pin[1]是一个char类型
    while(*(StrIn+i) != '\0' && *(StrIn+i) == ' '){
        i++;
    }
    j = strlen(StrIn) - 1;
    while(*(StrIn+j) != '\0' && *(StrIn+j) == ' '){
        j--;
    }
    index = j-i+1;
    strncpy(StrOut,StrIn+i,index);
    return ErroMsg;
}

int main0(){
    char *p = "     hjkaghsdfhasf   ghjasdg    ";
    char buf[100];
    int ErroMsg = 0;
    ErroMsg = RemoveSpace(p,buf);
    if (ErroMsg != 0){
        printf("GetStr1(p,buf) Erro Msg key : %d\n",ErroMsg);
        return ErroMsg;
    }

    printf("p:'%s'\nbuf:'%s'\n",p,buf);

    printf("Hello world\n");
    return ErroMsg;
}

int StrReverse(char *str){
    int ErroMsg = 0;
    char *begin;
    char *end;
    char tmp;
    int len;
    if (str == NULL){
        ErroMsg = -1;
        printf("str == NULL Erro Msg key:%d\n",ErroMsg);
        return ErroMsg;
    }
    begin = str;
    len = strlen(str) - 1;
    end = str + len;
    while (begin < end){
        tmp = *begin;
        *begin = *end;
        *end = tmp;
        begin++;
        end --;
    }

    return ErroMsg;
}
int main1(){
    int ErroMsg = 0;
    char buf[] = "khjfghjkasgfhjghf";

    printf("buf:%s\n",buf);
    ErroMsg = StrReverse(buf);
    if (ErroMsg != 0){
        printf(" StrReverse(buf) Erro Msg key :%d\n",ErroMsg);
        return ErroMsg;
    }
    printf("buf:%s\n",buf);

    printf("Hello World!\n");
    return ErroMsg;
}

int StrReverse2(char *StrIn,char *StrOut){
    int ErroMsg = 0;
    if ( StrIn == NULL || StrOut == NULL){  //递归异常条件
        ErroMsg = -1;
        printf(" StrIn == NULL || StrOut == NULL ErroMsg key :%d\n",ErroMsg);
        return ErroMsg;
    }
    if ( *StrIn == '\0'){    // 递归结束条件
        return 0;
    }
    ErroMsg = StrReverse2(StrIn+1,StrOut);
    strncat(StrOut,StrIn,1);

    return ErroMsg;
}
int main(){
    int ErroMsg = 0;
    char *p = "abcdefgh";
    char buf[200];
    
    memset(buf,0,sizeof(buf));
    ErroMsg = StrReverse2(p,buf);
    if (ErroMsg != 0){
        printf("StrReverse2(p,buf) ErroMsg key : %d\n",ErroMsg);
        return ErroMsg;
    }
    printf("p:%s\nbuf:%s\n",p,buf);
    return ErroMsg;
}
