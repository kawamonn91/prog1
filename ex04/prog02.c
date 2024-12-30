#include<stdio.h>
int main()
{
    double a,b;
    double *p,*q;

    //ポインタに代入
    p=&a;
    q=&b;

    printf("aの値を入力\n");
    scanf("%lf",&a);
    printf("bの値を入力\n");
    scanf("%lf",&b);

    printf("aの値:%.1f,aのアドレス:%p\n",*p,p);
    printf("bの値:%.1f,bのアドレス:%p\n",*q,q);
    printf("積:%.1f\n",(*p)*(*q));
    printf("商:%.1f\n",(*p)/(*q));

    return 0;
}