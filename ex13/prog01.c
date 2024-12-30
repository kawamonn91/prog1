#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
    int l,count=0;
    char str1[128],*str2[N];
    while(scanf("%s",str1)==1)
    {
        //長さを求める
        l=strlen(str1);
        //長さ＋終端文字分のメモリを確保
        str2[count]=(char *)malloc((l+1) *sizeof(char));\
        if(str2[count]==NULL)
        {
            printf("メモリの割り当てに失敗しました\n");
        }
        //str2にコピー
        strcpy(str2[count],str1);
        count++;
    }

    for(int i=0;i<count;i++)
    {
        l=strlen(str2[i]);
        printf("%d:%s[%d]\n",i,str2[i],l);
    }

    return 0;
}