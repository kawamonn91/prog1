#include<stdio.h>
int myatoi(char *);

int main()
{
    char str2[][20]={"2024",
                    "-21.50",
                    "+16m",
                    "654,321",
                    "+-40",
                    "-x86",
                    "2024/1/31",
                    ""};
    int ival,i;

    for(i=0;str2[i][0]!='\0';i++)
    {
        ival=myatoi(str2[i]);
        printf("String:%s\n",str2[i]);
        printf("Value:%d\n",ival);
    }
    return 0;
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