#include<stdio.h>
#define N 100
int eliminate(char c);
int main()
{
    char str1[N],str2[N];
    int i=1,flag=0;

    printf("Input string: ");
    scanf("%s",str1);

    str2[0]='[';
    for(int j=0;str1[j]!='\0';j++)
    {
        //母音が含まれているか判定
        flag=eliminate(str1[j]);
        //子音だった場合ster2に代入
        if(flag==0) 
        {
            str2[i]=str1[j];
            i++;
        }
    }
    //i++;
    str2[i]=']';
    str2[i+1]='\0';

    printf("str1 :%s\n",str1);
    printf("str2: %s\n",str2);

    return 0;
}

int eliminate(char c)
{
    int result=0;
    char vowel[10]={'a','i','u','e','o','A','I','U','E','O'};
    for(int i=0;i<10;i++)
    {
        if(c==vowel[i]) result=1;
    }
    return result;
}