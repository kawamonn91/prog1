#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 100
void lconv(char*);
int main()
{
    int l,count=0,flag=0;
    char str1[128],*str2[N];
    int count_str[N];
    //printf("count_strの初期化\n");
    for(int i=0;i<N;i++)
    {
        count_str[i]=0;
    }
    while(scanf("%s",str1)==1)
    {
        flag=0;
        //printf("長さを求める\n");
        l=strlen(str1);
        //printf("sttr1の中身を小文字化。カンマ、ピリオドの除去\n");
        lconv(str1);
        if(count!=0)
        {
            //printf("単語の探索\n");
            for(int i=0;i<count;i++)
            {
                if(strcmp(str1,str2[i])==0) 
                {
                    count_str[i]++;
                    flag=1;
                }
            }
        }
        
        if(flag==0)
        {
           //printf("長さ＋終端文字分のメモリを確保\n");
            str2[count]=(char *)malloc((l+1) *sizeof(char));
            if(str2[count]==NULL)
            {
                printf("メモリの割り当てに失敗しました\n");
            }
        
            //printf("str2にコピー\n");
            strcpy(str2[count],str1);
            count_str[count]++;
            count++;
        }
    }

    for(int i=0;i<count;i++)
    {
        l=strlen(str2[i]);
        printf("%d:%s[%d](%d)\n",i,str2[i],l,count_str[i]);
    }

    return 0;
}

void lconv(char *p)
{
    int n=1;
    while(n!=0)
    {
        n=*p;
        if((n>=65&&n<=90)||(n>=97&&N<=122))
        {
            *p=tolower(*p);
        }
        else *p='\0';
        p++;
    }
}