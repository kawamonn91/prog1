#include<stdio.h>
#include"prog01.h"

#define YEAR 2024
#define MONTH 10
#define DAY 28

My_record input(void);
void output(My_record data);
int get_age(My_record data);
int age;

int main()
{
    My_record data=input();
    age=get_age(data);
    output(data);
    return 0;
}

My_record input(void)
{
    My_record data;
    printf("-----データ入力-----\n");
    printf("データを入力して下さい\n");
    printf("名字->");
    scanf("%s",data.lastname);
    printf("名前->");
    scanf("%s",data.firstname);
    printf("性別(Male/Female)->");
    scanf("%s",data.gender);
    printf("生まれた年(西暦)->");
    scanf("%d",&data.birthday[0]);
    printf("生まれた月->");
    scanf("%d",&data.birthday[1]);
    printf("生まれた日->");
    scanf("%d",&data.birthday[2]);

    printf("氏名:%s %s\n",data.lastname,data.firstname);
    printf("性別:%s\n",data.gender);
    printf("生年月日: %d/%d/%d\n",data.birthday[0],data.birthday[1],data.birthday[2]);

    return data;
}

void output(My_record data)
{
    printf("-----データ出力-----\n");
    printf("年齢基準日:%d/%d/%d\n",YEAR,MONTH,DAY);
    printf("氏名:%s%s\n",data.lastname,data.firstname);
    printf("性別:%s\n",data.gender);
    printf("生年月日:%d/%d/%d\n",data.birthday[0],data.birthday[1],data.birthday[2]);
    printf("年齢:%d\n",age);
}

int get_age(My_record data)
{
    age=YEAR-data.birthday[0];
    if(MONTH<data.birthday[1]||(MONTH==data.birthday[1]&&DAY<data.birthday[2])) age--;
    return age;
}