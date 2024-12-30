#include<stdio.h>
#include "prog01.h"
int main()
{
    My_record data;
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

    return 0;
} 