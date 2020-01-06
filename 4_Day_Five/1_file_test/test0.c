#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "cif_dw.h"

#define KEYMAX      100
#define VALUEMAX    200
#define FILENAME    "test.cif"

void Menu(){
    printf ("<------------------------------->\n");
    printf ("\t1 -> Write config file!\n");
    printf ("\t2 -> Read  config file!\n");
    printf ("\t0 -> exit!             \n");
    printf ("<------------------------------->\n");
    printf ("\t     Input Display : ");
    return ;
}

// 写配置文件
//int WriteConfigFile(const char *_in_file_name, const char *_in_key, const char *_in_value);

// 读配置文件
//int ReadConfigFile (const char *_in_file_name, const char *_in_key, char **_inout_value);


void TWriteConfig(){
    char    key[KEYMAX] = {0};
    char    value[VALUEMAX] = {0};
    int     ErroMsg = 0;
    char    *file_name = FILENAME;

    printf ("\tPlease input key:");
    scanf  ("%s",key);

    printf ("\tPlease input value:");
    scanf  ("%s",value);

    ErroMsg = WriteConfigFile(file_name, key, value);
    if (ErroMsg != 0){
        printf ("Func WriteConfigFile() ErroMsg :%d\n",ErroMsg);
        return;
    }
    
    printf ("\t%s = %s\n",key,value);
    printf ("\tConfig write success!\n");

    return;
}

void TReadConfig(){
    char    key[KEYMAX] = {0};
    char    value[VALUEMAX] = {0};
    int     ErroMsg = 0;
    char    *file_name = FILENAME;

    printf ("\tPlease input key:");
    scanf  ("%s",key);
    
    ErroMsg = ReadConfigFile(file_name, key, value);
    if (ErroMsg != 0){
        printf ("Func ReadConfigFile() ErroMsg :%d\n",ErroMsg);
        return;
    }
    if (value[0] != 0){
        printf ("\t%s = %s\n",key,value);
    }
    else{
        printf ("\tThe %s not found!\n",key);
    }
    return;
}


int main(){
    int ErroMsg = 0;
    int choice = 0;
    while (1){
        Menu();
        choice = 10;
        scanf ("%d",&choice);
        switch (choice){
        case 1:
            TWriteConfig();
            break;
        case 2:
            TReadConfig();
            break;
        case 0:
            exit(0);
        default:
            continue;
        }
    }

    printf("Hello world\n");
    return 0;
}

