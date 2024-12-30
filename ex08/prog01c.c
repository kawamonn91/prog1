typedef struct 
{
    int id;
    char name[12];
    int year;
    char subject[12];
    char grade;
}StudentInfo;

#define N 20
void PrintInfo(StudentInfo);
void PrintInfoPtr(StudentInfo *);
int InputInfo(StudentInfo *);
#include<stdio.h>
int main()
{
    StudentInfo *p;
    StudentInfo studentdata[N];
    p=studentdata;
    int count=0;
    while(InputInfo(p)!=1)
        {
            p++;
            count++;
        }
    
    
    printf("構造体の値渡し\n");
    for(int i=0;i<count;i++)
    {
        PrintInfo(studentdata[i]);
    }

    printf("構造体のアドレス渡し\n");
    p=&studentdata[0];
    for(int i=0;i<count;i++)
    {
        PrintInfoPtr(p);
        p++;
    }

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

int InputInfo(StudentInfo *p)
{
    if(scanf("%d %s %d %s %c",&p->id,p->name,&p->year,p->subject,&p->grade)!=5) return 1;
    return 0;
}