typedef struct 
{
    int id;
    char name[12];
    int year;
    char subject[12];
    char grade;
}StudentInfo;

void PrintInfo(StudentInfo);
void PrintInfoPtr(StudentInfo *);
#include<stdio.h>
int main()
{
    StudentInfo *p;
    StudentInfo student1={1319991,"Fukusima",3,"Literacy",'B'};
    StudentInfo student2={1319992,"Wakamatu",2,"Programing",'A'};
    
    printf("構造体の値渡し\n");
    PrintInfo(student1);
    PrintInfo(student2);

    printf("構造体のアドレス渡し\n");
    p=&student1;
    PrintInfoPtr(p);
    p=&student2;
    PrintInfoPtr(p);

    return 0;
}

void PrintInfo(StudentInfo info)
{
    printf("%d %s %d %s %c\n",info.id,info.name,info.year,info.subject,info.grade);
}

void PrintInfoPtr(StudentInfo *p)
{
    printf("%d %s %d %s %c\n",p->id,p->name,p->year,p->subject,p->grade);
}