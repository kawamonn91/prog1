#include<stdio.h>
int main()
{
    char str1[10]={'0','1','2','3','4','5','6','7','8','9'};
    char str2[4]={'-','+','/',' '};
    for(int i=0;i<10;i++)
    {
        printf("%d ",str1[i]);
    }
    printf("\n");

    for(int i=0;i<4;i++)
    {
        printf("%d ",str2[i]);
    }
    printf("\n");

    return 0;
}