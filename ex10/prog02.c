#include<stdio.h>
#include<stdlib.h>
int myatoi (char *);
int main()
{
    char str1[1],str2[2];
    int year;
    printf("和暦(S45,R6等):");
    scanf("%c",&str1);
    scanf("%s",&str2);
    year=myatoi(str2);
    if(year==0)
    {
        printf("数字を読み取れません\n");
        exit(2);
    }
    if(str1[0]=='R')
    {
        year=year+2018;
    }
    else if(str1[0]=='H')
    {
        year=year+1988;
    }
    else if(str1[0]=='S')
    {
        year=year+1925;
    }
    else if(str1[0]=='T')
    {
        year=year+1911;
    }
    else if(str1[0]=='M')
    {
        year=year+1867;
    }
    else
    {
        printf("%cに対応する元号がありません\n",str1[0]);
        exit(1);
    }


    
    printf("西暦(AD):%d\n",year);

}

int myatoi(char *p)
{
    int m=0,count=0,total=0;
    int n;
    while(*p)
        {
            n=*p;
            if(n<48||n>57)
            {
                if(n==45||n==43)
                {
                    m++;
                    if(m==2)
                    {
                        n=0;
                        m=0;
                        return n;
                    }
                }
                else
                {
                    return total;
                }
            }

            if(n>=48&&n<=57)
            {
                total=total*10;
                n=n-48;
                total+=n;
            }
            p++;
        }
        return total;
}