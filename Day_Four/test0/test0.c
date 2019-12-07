#include "string.h"
#include "stdlib.h"
#include "stdio.h"


// C语言数组实现
int main(){
    // 数组类型
    typedef int (TypeArray)[10];
    // 数组类型变量
    TypeArray array;  // int array[10];
    int i = 0;
    for (i = 0;i < 10;i++){
        array[i] = i+1;
        printf("%d\t",array[i]);
    }
    printf("\n");

    printf("array :%d\tarray+1 :%d\n",array,array+1);
    printf("&array:%d\t&array+1:%d\n",&array,&array+1);
    // array :-1093118844      array+1 :-1093118840 数组名表示数组首元素地址
    // &array:-1093118844      &array+1:-1093118804 数组名取地址表示数组地址
    {
        //数组类型指针变量
        TypeArray *PArray;
        PArray = &array;
        for (i = 0;i < 10;i++){
            printf("%d\t",(*PArray)[i]);
        }
    }
    {
        //数组指针类型
        typedef int (*TypePointerArray)[10];
        //数组指针类型变量
        TypePointerArray PArray2;
        PArray2 = &array;
        for (i = 0;i < 10;i++){
            printf("%d\t",(*PArray2)[i]);
        }
    }
    {
        int (*PArray3)[10];
        PArray3 = &array;
        for (i = 0;i < 10;i++){
            printf("%d\t",(*PArray3)[i]);
        }
    }

    printf("\nHello world\n");
    return 0;
}

