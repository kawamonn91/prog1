#include<stdio.h>
#include<stdlib.h>
int fibo(int);
int fibo_array(int,int *);

int main()
{
    int n,result;
    printf("項数nの値を入力して下さい。\n");
    printf("n=");
    scanf("%d",&n);

    result=fibo(n);

    printf("fibo(%d)=%d\n",n,result);

    //動的メモリ割り当て
    int *array=(int *)malloc((n+1) * sizeof(int));
    for(int i=0;i<=n;i++)
    {
        array[i]=-1;
    }
    result=fibo_array(n,array);
    printf("fibo_array(%d)=%d\n",n,result);
    free(array);
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

int fibo_array(int n,int *array)
{
    static int times=0;
    times++;
    printf("called %d times:n=%d\n",times,n);
    if(array[n]==-1)
    {
        if(n==0) 
        {
            array[n]=0;
            return array[n];
        }
        else if(n==1)
        {
            array[n]=1;
            return array[n];
        }
        else
        {;
            array[n]=fibo_array(n-1,array)+fibo_array(n-2,array);
            return array[n];
        }
    }
    else return array[n];
}