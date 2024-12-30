#include<stdio.h>
struct my_record{
        char lastname[20];//名字
        char firstname[20];//名前
        char gender[7];//性別
        int birthday[3];//生年月日(要素0:西暦、要素1:月、要素2:日)
    };
int main()
{
    struct my_record data;
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