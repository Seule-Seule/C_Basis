#include "string.h"
#include "stdlib.h"
#include "stdio.h"
 
int main(){
    // 结构体类型定义
    struct teacher{
        char name[10];
        int age;
        int id;
    };
    typedef struct student{
        char name[10];
        int age;
    }student;

   // 结构体变量定义
    struct teacher t1;
    
    struct teacher1{
        char name[10];
        int age;
        int id;
    }t2,t3;

    struct {
        char name[10];
        int age;
        int id;
    }t4,t5;

    // 结构体变量初始化
    student s1 = {"s1name",11};

    struct teacher3{
        char name[10];
        int age;
        int id;
    }t6 = {"t6name",66,06};

    struct {
        char name[10];
        int age;
        int id;
    }t7 = {"t7name",77,07};

    // 结构体变量引用
    printf("s1.name:%s\n",s1.name);
    // . n表示寻址操作 由CPU完成
    {
        student *ps1 = &s1;
        printf("ps1->age:%d\n",ps1->age);
    }
    
    printf("Hello world\n");
    return 0;
}

