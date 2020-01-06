#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main0(){
    int len = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    char buf[128];
    char to[128];

    strcpy(buf, "wegsdgasjfuhfksjafh");
    printf("buf:%s\n",buf);
    p1 = buf;
    p2 = to;
    while( *p1 != '\0'){
        *p2 = *p1;
        p1++;
        p2++;
    }
    printf("to:%s\n",to);

    printf("Hello world\n");
    return 0;
}

// out out out out
int GetMey1(char **array1, int *len1, char **array2, int *len2){
    *array1 = (char *)malloc(100);
    if ( *array1 == NULL){
        return -1;
    }
    strcpy(*array1, "12343534646455");
    *len1 = strlen(*array1);
    *array2 = (char *)malloc(100);
    if ( *array2 == NULL){
        return -1;
    }
    strcpy(*array2, "akjfiafjafjsf");
    *len2 = strlen(*array2);

    return 0;
}

int main1(){
    int len = 0;
    int len2 = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    
    GetMey1(&p1,&len,&p2,&len2);

    printf("p1:%s\nlen1:%d\n",p1,len);
    printf("p2:%s\nlen2:%d\n",p2,len2);
    if (p1 != NULL){
        free(p1);
        p1 = NULL;
    }
    if (p2 != NULL){
        free(p2);
        p2 = NULL;
    }

    printf("Hello world\n");
    return 0;
}

// in out in out
int GetMey2(char **array1, int *len1, char **array2, int *len2){
    if ( *array1 == NULL){
        return -1;
    }
    strcpy(*array1, "12343534646455");
    *len1 = strlen(*array1);
    if ( *array2 == NULL){
        return -1;
    }
    strcpy(*array2, "akjfiafjafjsf");
    *len2 = strlen(*array2);

    return 0;
}

int main(){
    int len = 0;
    int len2 = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = (char *)malloc(100);
    p2 = (char *)malloc(100);
    GetMey2(&p1,&len,&p2,&len2);

    printf("p1:%s\nlen1:%d\n",p1,len);
    printf("p2:%s\nlen2:%d\n",p2,len2);
    if (p1 != NULL){
        free(p1);
        p1 = NULL;
    }
    if (p2 != NULL){
        free(p2);
        p2 = NULL;
    }

    printf("Hello world\n");
    return 0;
}

