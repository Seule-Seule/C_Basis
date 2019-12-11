#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Teacher{
    char name[20];
    int  age;
    char *AlisName;
}Teacher;

void TeacherPrint(Teacher *p){
    if (p == NULL){
        return;
    }
    printf("name:%-20s\tage:%4d\tAlisName:%-20s\n",p->name,p->age,p->AlisName);

}

int TeacherCopy(Teacher *to,Teacher *from){
    *to = *from;  // 浅拷贝
    

    // 深拷贝
    to->AlisName = (char *)malloc(sizeof(char) * 20);
    if (to->AlisName == NULL){
        return -1;
    }
    strcpy(to->AlisName,from->AlisName);
    return 0;
}

int main(){
    int ErroMsg = 0;
    Teacher t1;
    Teacher t2;
    strcpy(t1.name,"1111");
    t1.age = 21;
    t1.AlisName = (char *)malloc(sizeof(char)*20);
    strcpy(t1.AlisName,"AlisName1");
    
    TeacherPrint(&t1);

    ErroMsg = TeacherCopy(&t2,&t1);
    if (ErroMsg != 0){
        printf("Func ErroMsg = TeacherCopy(&t2,&t1) ErroMsg key:%d\n",ErroMsg);
    }
    TeacherPrint(&t2);

    if (t1.AlisName != NULL){
        free(t1.AlisName);
    }
    if (t2.AlisName != NULL){
        free(t2.AlisName);
    }

    printf("Hello world\n");
    return ErroMsg;
}

