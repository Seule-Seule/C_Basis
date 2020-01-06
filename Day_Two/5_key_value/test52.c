#include "string.h"
#include "stdlib.h"
#include "stdio.h"


int RmSpace(char *InStr){
    char *In = InStr;
    char *tmp = NULL;
    int len = 0;
    if (In == NULL){
        printf("Get error memory address!");
        return -1;
    }
    while(*In == ' '){
        tmp = ++In;
    }
    len = strlen(In) - 1;
    while(*(In+len) == ' '){
        *(In+len--) = '\0';
    }
    return 0;
}

// 键值对
int GetValue(char *KeyValueBuf,char *KeyBuf,char *ValueBuf,int *ValueLen){
    char *KeyValue = KeyValueBuf;
    char *Key = KeyBuf;
    char *Value = ValueBuf;
    int ret =0;
    int i =0;
    
    while(*(KeyValue+i++) != '=');
    strcpy(Key,KeyValue);
    *(Key+i-1) = '\0';
    strcpy(Value,KeyValue+i+1);
    ret = RmSpace(Key);
    ret = RmSpace(Value);
    if (ret != 0){
        printf("Error! RmSpace() ?\n");
    }
    *ValueLen = strlen(ValueBuf);
    return ret;
}
int main(){
    char *p = "kay1 = value1     ";
    char key[100];
    char value[100];
    int ret = 0;
    int ValueLen = 0;
    
    ret = GetValue(p,key,value,&ValueLen);
    if (ret != 0){
        printf("Error! GetValue() ? ");
    }
    printf("key:'%s'\n",key);
    printf("value:'%s'\n",value);
    printf("Hello world\n");
    return ret;
}

