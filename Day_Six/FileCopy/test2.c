#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcopy.h"

int main(){
    int     ErroMsg = 0;
    char    *from_filename = "test.txt";
    char    *to_filename = "test.txt.bak";

    ErroMsg = FileCopy(from_filename, to_filename);
    if (ErroMsg != 0){
        printf("Func  FileCopy(from_filename, to_filename) ErroMsg : %d\n",ErroMsg);
    }

    printf("Hello world\n");
    return 0;
}

