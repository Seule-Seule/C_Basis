#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char *argv[], char **env){
    int i = 0;

    printf("argc:%d\nargv:\n",argc);
    for (i = 0;i < argc;i++){
        printf("'%s'\n",*(argv+i));
    }
    
    printf("env:\n");
    for (i = 0;*(env+i) != NULL;i++){
        printf("%s\n",*(env+i));
    }

    printf("Hello world\n");
    return 0;
}

