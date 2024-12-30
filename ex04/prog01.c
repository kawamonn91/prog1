#include<stdio.h>
int main()
{
    int data=312;
    int*p;
    p=&data;

    printf("%p\n",&data);
    printf("%d\n",data);
    //printf("%p\n",*data);
    printf("%p\n",&p);
    printf("%p\n",p);
    printf("%d\n",*p);
    printf("%p\n",&(*p));

    return 0;

}