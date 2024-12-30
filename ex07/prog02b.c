#include<stdio.h>
#include"prog01.h"

#define YEAR 2024
#define MONTH 10
#define DAY 28
#define N 20

My_record input(void);
void output(My_record data);
int get_age(My_record data);

int main()
{   
    printf("-----データ出力-----\n");
    printf("年齢基準日:%d/%d/%d\n",YEAR,MONTH,DAY);
    My_record data=input();
    return 0;
}

My_record input(void)
{
    My_record data;
    for(int i=0;i<N;i++)
    {
        if(scanf("%s",data.lastname)==EOF) 
        {
            data.birthday[0]=-1;
            break;
        }

        scanf("%s",data.firstname);
        scanf("%s",data.gender);
        scanf("%d",&data.birthday[0]);
        scanf("%d",&data.birthday[1]);
        scanf("%d",&data.birthday[2]);
        output(data);
    }
    return data;

}

void output(My_record data)
{
    int age=get_age(data);
    printf("氏名:%s  %s  ",data.lastname,data.firstname);
    printf(",性別:%s",data.gender);
    printf(",生年月日:%d/%d/%d",data.birthday[0],data.birthday[1],data.birthday[2]);
    printf(",年齢:%d\n",age);
}

int get_age(My_record data)
{
    int age=YEAR-data.birthday[0];
    if(MONTH<data.birthday[1]||(MONTH==data.birthday[1]&&DAY<data.birthday[2])) age--;
    return age;
}