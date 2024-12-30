#include<stdio.h>
int fibo(int);

int main()
{
    int n,result;
    printf("項数nの値を入力して下さい。\n");
    printf("n=");
    scanf("%d",&n);

    result=fibo(n);

    printf("fibo(%d)=%d\n",n,result);
    return 0;
}

int fibo(int n)
{
    static int times=0;
    times++;
    printf("called %d times: n=%d\n",times,n);
    
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibo(n-1)+fibo(n-2);
}