#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main(){
    const int a = 10;
    const char *p = "abcd";
    char * const p2 = "afdkjfh";
    const char * const p3 = "anjdhfjksdhf";

    {
        p = "ashfbadf";     // pointer can change!
        *p2 = "adjhfkjah"; // pointer can not change! But pointer sddress variable can change!
        //p2  pointer and pointer address variable can not change.
        //
    }
    {
        // a = 100; // Error const a can not change.
        int *p4 = &a;  
        *p4 = 100;  // change a with pointer.
    }

    printf("a:%d\n",a);

    printf("Hello world\n");
    return 0;
}

