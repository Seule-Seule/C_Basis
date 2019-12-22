#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcopy.h" 

#define     MAXFILECACHE    4096 // 4K  


__declspec(dllexport)
int FileCopy(const char *_from_filename, const char *_to_filename){
    int     ErroMsg = 0;
    FILE    *form_file = NULL;
    FILE    *to_file = NULL;
    char    cache_buf[MAXFILECACHE] = {0};
    int     tmp;
    char    *to_file_bak = NULL;

    form_file = fopen(_from_filename, "r");
    if (form_file == NULL){
        ErroMsg = -1;
        printf("File %s opem fail!\n",_from_filename);
        goto END;
    }
    
    to_file = fopen(_to_filename, "r");
    if (to_file == NULL){
        to_file = fopen(_to_filename, "w+");
        if (to_file == NULL){
            ErroMsg = -2;
            printf("Build file %s fail!\n", _to_filename);
            goto END;
        }
    }
    else {
        to_file_bak = (char *)malloc(sizeof(char) * (strlen(_to_filename)) + 5);  // 如果备份文件存在则备份备份文件.bak结尾
        strcpy(to_file_bak, _to_filename);
        strcat(to_file_bak, ".bak");
        if (to_file_bak == NULL){
            printf("Get memory fail!\n");
            ErroMsg = -4;
            goto END;
        }
        ErroMsg = FileCopy(_to_filename, to_file_bak);  
        if (ErroMsg != 0){
            printf ("Wrring : ErroMag %d\n", ErroMsg);
            ErroMsg = -5;
        }
        to_file = fopen(_to_filename, "w+");
        if (to_file == NULL){
            ErroMsg = -6;
            printf("Build file %s fail!\n", _to_filename);
            goto END;
        }
        printf("File %s existing, and we build new file for %s named %s!\n",_to_filename, _to_filename, to_file_bak);
        ErroMsg = -3;
    }
            
    while(!feof(form_file)){
        tmp = fread(cache_buf, 1, MAXFILECACHE, form_file);
        if (tmp < MAXFILECACHE){      // 大小不足cache, 在外面加密
            // 嵌入不足cache部分数据加密函数
            fwrite(cache_buf, tmp, 1, to_file);
            break;
        }
        // 嵌入加密函数
        fwrite(cache_buf, MAXFILECACHE, 1, to_file);
    }

END:
    if (ErroMsg == -1){
  //      fclose(form_file);
        return ErroMsg;
    }
    if (ErroMsg == -2){
        fclose(form_file);
        fclose(to_file);
        return ErroMsg;
    }
    if (ErroMsg == -3){
        free(to_file_bak);
        to_file_bak = NULL;
    }
    if (ErroMsg == -5){
        free(to_file_bak);
        to_file_bak = NULL;
    }

    fclose(form_file);
    fclose(to_file);
    return ErroMsg;
}

