#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Student{
    char name[10];
    char *AlisName;
    char **TeacherName;
    int  age;
    int  id;
}Student;

void PrintStudentArray(const Student *p,int len,int TeaLen){
    int     i = 0,j = 0;
    
    for (i = 0;i < len;i++){
        printf("name:%-10s\tage:%-4d\tid:%-4d\tAlisname:%-20s\n",p[i].name,p[i].age,p[i].id,p[i].AlisName);
        for (j = 0;j < TeaLen;j++){
            printf("His(Her) teacher number %-4d is :%-20s\n",j,p[i].TeacherName[j]);
        }
    }

    return ;
}

void SortStudentArrayAsAge(Student *p,int len){
    int     i = 0,j = 0;
    Student tmp;
    for (i = 0;i < len;i++){
        for (j = i+1;j < len;j++){
            if (p[i].age < p[j].age){
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    return ;
}

int CreateStudentArray(Student **p,int len,int TeaLen){
    Student *tmp = NULL;
    int     i = 0,j = 0;
    int     ErroMsg = 0;
    tmp = (Student *)malloc(sizeof(Student) * len);
    if (tmp == NULL){
        ErroMsg = -1;
        goto END;
    }

    for (i = 0;i < len;i++){
        tmp[i].AlisName = (char *)malloc(sizeof(char) * 20);
        if (tmp[i].AlisName == NULL){
            ErroMsg  = -2;
            goto END;
        }
        tmp[i].id = i;
        {
            char **TeaNameTmp = (char **)malloc(sizeof(char *) * TeaLen);
            if (TeaNameTmp == NULL){
                ErroMsg = -3;
                goto END;
            }
            for (j = 0;j < TeaLen;j++){
                TeaNameTmp[j] = (char *)malloc(sizeof(char )* 20);
                if (TeaNameTmp[j] == NULL){
                    ErroMsg = -4;
                    goto END;
                }
            }
            tmp[i].TeacherName = TeaNameTmp;
        }
    }
END:
    if (ErroMsg == -4){
        for (i = 0;i < len;i++){
            if (tmp[i].AlisName != NULL){
                free(tmp[i].AlisName);
            }
            for (j = 0;j < TeaLen;j++){
                if (tmp[i].TeacherName[j] != NULL){
                    free(tmp[i].TeacherName[j]);
                }
            }
            free(tmp[i].TeacherName);
        }
        free(tmp);
    }
    if (ErroMsg == -3){
        for (i = 0;i < len;i++){
            if (tmp[i].AlisName != NULL){
                free(tmp[i].AlisName);
            }
            if (tmp[i].TeacherName != NULL){
                free(tmp[i].TeacherName);
            }
        }
        free(tmp);
    }
    if (ErroMsg == -2){
        for (i = 0;i < len;i++){
            if (tmp[i].AlisName != NULL){
                free(tmp[i].AlisName);
            }
        }
        free(tmp);
    }
    else if (ErroMsg == -1){
        free(tmp);
    }
    else {
        *p = tmp;
    }
    return ErroMsg;
}

int FreeStudentArray(Student *p,int len,int TeaLen){
    int i = 0,j = 0;
    if (p == NULL){
        return -1;
    }

    for ( i = 0;i < len;i++){
        if (p[i].AlisName != NULL){
            free(p[i].AlisName);
        }
        for (j = 0;j < TeaLen;j++){
            if (p[i].TeacherName[j] != NULL){
                free(p[i].TeacherName[j]);
            }
        }
        free(p[i].TeacherName);
    }
    free(p);
    return 0;
}


int main(){
    Student s0[2];
    int     ErroMsg = 0;
    int     i = 0,j = 0;
    int     num = 3;
    Student *s1;
    int     len = 3;
    int     ErroMsgc = 0;
    int     TeaLen = 3;

    ErroMsg = CreateStudentArray(&s1,len,TeaLen);
    if (ErroMsg != 0){
        printf("Func ErroMsgc = CreateStudentArray(&s1,len); ErroMsg key : %d\n",ErroMsg);
    }
    for (i = 0;i < 3;i++){
        printf("Please input name for %d student:",i);
        scanf("%s",s1[i].name);
        printf("Please input age for %s student:",s1[i].name);
        scanf("%d",&s1[i].age);
        printf("Please input alisname for %s student:",s1[i].name);
        scanf("%s",s1[i].AlisName);
        for (j = 0;j < TeaLen;j++){
            printf("Please input teacher name for %s number %d:",s1[i].name,j);
            scanf("%s",s1[i].TeacherName[j]);
        }
    }

   // for (i = 0;i < num;i++){
   //     printf("The age of %d student:%d\n",i,s0[i].age);
   // }
    PrintStudentArray(s1,num,TeaLen);

    SortStudentArrayAsAge(s1,num);

    PrintStudentArray(s1,num,TeaLen);

    ErroMsg = FreeStudentArray(s1,len,TeaLen);
    if (ErroMsg != 0){
        printf("Func ErroMsg = FreeStudentArray(s1,len); ErroMsg key:%d",ErroMsg);
    }

    printf("Hello world\n");
    return 0;
}

