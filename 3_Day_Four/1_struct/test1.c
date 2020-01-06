#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Student{
    char name[10];
    int age;
    int id;
}Student;

int StructCpoy(Student to,Student from){
    to = from;    // 垃圾语句修改局部变量，不能输出！
    return 0;
}

int StructCopy1(Student *to,Student *from){
    *to = *from;
    return 0;
}

int main(){
    Student s1 = {"faner",20,00};
    Student s2;
    Student s3;
    Student s4;

    s2 = s1;   // 直接赋值

    printf("\n直接拷贝:\n");
    printf("s2.name:%s\n",s2.name);
    
    printf("\nStructCpoy(s3,s1);\n");
    StructCpoy(s3,s1);
    printf("s3.age:%d\n",s3.age);

    printf("\nStructCopy1(&s4,&s1);\n");
    StructCopy1(&s4,&s1);
    printf("s4.id:%d\n",s4.id);

    printf("Hello world\n");
    return 0;
}

