#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main0(){
    FILE    *fp;
    char    buf[] = "abcdefghthshshsh";
    int     i = 0;
    char    tmpc;

    fp = fopen("test.txt","w+");
    if (fp == NULL){
        printf("File open fail!");
        return  -1;
    }
    
    for (i = 0;i < strlen(buf);i++){
        fputc(buf[i],fp);
    }
    printf ("File write success!\n");
    fclose(fp);

    fp = fopen("test.txt","r");
    while (!feof(fp)){
        tmpc = fgetc(fp);
        printf("%c",tmpc);
    }

    fclose(fp);

    printf("\nHello world\n");
    return 0;
}

int main1(){
    FILE    *fp;
    char    buf[] = "abcdefghthshshsh";
    int     i = 0;
    char    *tmpc;
    char    buf2[1024];

    fp = fopen("test.txt","w+");
    if (fp == NULL){
        printf("File open fail!");
        return  -1;
    }
    
    fputs(buf,fp);
    printf ("File write success!\n");
    fclose(fp);

    fp = fopen("test.txt","r");

    while (!feof(fp)){
        tmpc = fgets(buf2,1024,fp);
        printf ("%s\n",tmpc);
    }
    fclose(fp);

    printf("\nHello world\n");
    return 0;
}

int main(){
    FILE    *fp;
    char    buf[] = "abcdefghthshshsh";
    int     i = 0;
    int     Count = 0;
    char    buf2[1024];

    fp = fopen("test.txt","wb");
    if (fp == NULL){
        printf("File open fail!");
        return  -1;
    }
    
    Count = fwrite(buf,sizeof(buf),1,fp);
    if (Count == 1){
        printf ("File write success!\n");
    }
    fclose(fp);

    fp = fopen("test.txt","rb");
    Count = fread(buf2,sizeof(buf),1,fp);
    if (Count == 1){
        printf ("File read success!\n");
    }
    printf ("%s\n",buf2);
    fclose(fp);

    printf("\nHello world\n");
    return 0;
}

