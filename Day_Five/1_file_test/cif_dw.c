#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "cif_dw.h"

#define     LINEMAX     2048
#define     FILEBUFMAX  2048*10

int RemoveSpace(char **_inout_str){
    char    *StrIn = *_inout_str;
    int     i = 0,j = 0;
    while(*(StrIn+i) != '\0' && *(StrIn+i) == ' '){
        i++;
    }
    j = strlen(StrIn) - 2;
    while(*(StrIn+j) != '\0' && *(StrIn+j) == ' '){
        j--;
        *(StrIn+j) = 0;
    }
    StrIn = StrIn + i;
    *_inout_str = StrIn;

    return 0;
}

// 写配置文件
int WriteConfigFile(const char *_in_file_name, const char *_in_key, const char *_in_value){
    int     ErroMsg = 0;
    FILE    *fp;
    char    *file_buf = NULL;
    int     file_size;
    char    line_buf[LINEMAX] = {0};
    char    *search_tmp = NULL;
    int     config_have_key_flag = 0;
    char    *key_value = NULL;
    int     key_value_len = 0;

    if (_in_value == NULL || _in_key == NULL || _in_file_name == NULL){
        ErroMsg = -1;
        printf ("_in_value == NULL || _in_key == NULL || _in_file_name == NULL ErroMsg : %d\n",ErroMsg);
        return ErroMsg;
    }
    
    key_value_len = strlen(_in_key) + strlen(_in_value) + 4; // 新加入串 "%s = %s\n" 长度
    key_value = (char *)malloc(sizeof(char) * key_value_len);
    sprintf (key_value, "%s = %s",_in_key, _in_value);
    
    fp = fopen(_in_file_name,"r+");
    if (fp == NULL){
        fp = fopen(_in_file_name, "w+");  // 创建文件
        if (fp == NULL){
            ErroMsg = -2;
            printf ("open file fail and try build file fail!\n");
            return ErroMsg;
        }
        fclose(fp);
        fp = fopen(_in_file_name,"r+");
    }
    
    //求得文件的大小
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (file_size > FILEBUFMAX){
        ErroMsg = -3;
        printf ("The config file is big than FILEBUFMAX . ErroMsg : %d\n",ErroMsg);
        return ErroMsg;
    }
    file_size = file_size + key_value_len; // %s = %s\n
    file_buf = (char *)malloc(sizeof(char) * file_size);
    if (file_buf == NULL){
        ErroMsg = -4;
        printf ("To apply for memory with file buf error. ErroMsg : %d\n",ErroMsg);
        return ErroMsg;
    }
    memset(file_buf, 0, sizeof(file_buf));
    
    while(fgets(line_buf, LINEMAX-1, fp)){
        search_tmp = strstr(line_buf, _in_key);
        if (search_tmp == NULL){  // 这一行没有key ， 缓冲，读下一行
            strcat(file_buf, line_buf);
            continue;
        }
        file_size = file_size - strlen(line_buf) ; 
        config_have_key_flag = 1;
    }

    strcat(file_buf, key_value); 
    fseek(fp, 0, SEEK_SET);
    fwrite(file_buf, file_size-1, 1, fp);

    if (key_value != NULL){
        free(key_value);
    }
    if (file_buf != NULL){
        free(file_buf);
    }
    if (fp != NULL){
        fclose(fp);
    }

    return 0;
}

// 读配置文件
int ReadConfigFile (const char *_in_file_name, const char *_in_key, char *_inout_value){
    int     ErroMsg = 0;
    FILE    *fp;
    char    line_buf[LINEMAX] = {0};
    char    *line_tmp = NULL;
    char    *search_tmp = NULL;
    int     line_flag  = 0;

    if (_in_file_name == NULL || _in_key == NULL || _inout_value == NULL){
        ErroMsg = -1;
        return -1;
    }
    fp = fopen(_in_file_name, "r");
    if (fp == NULL){
        ErroMsg = -2;
        return -2;
    }

    while (fgets(line_buf,LINEMAX-1,fp)){
        line_flag++;
        if (line_buf[0] == '"'){  //  注释行放弃搜索
            continue;
        }
        search_tmp = strchr(line_buf,'=');
        if (search_tmp == NULL ){
            ErroMsg =  -4;
            printf ("Func strchr(line_buf,=) Erro: not found = in line %d\n",line_flag);
            continue;
        }
        search_tmp = strstr(line_buf,_in_key);
        if (search_tmp == NULL){   // 这一行没有key ，下一行
            continue;
        }
        search_tmp = strchr(search_tmp,'=');
        search_tmp++;
        ErroMsg = RemoveSpace(&search_tmp);
        if (ErroMsg != 0){
            printf ("Func  RemoveSpace(search_tmp) remove speace in value ErroMsg : %d\n",ErroMsg);
            return ErroMsg;
        }
        strcpy(_inout_value,search_tmp);
    }
    if (fp != NULL){
        fclose(fp);
    }
    return ErroMsg;
}
