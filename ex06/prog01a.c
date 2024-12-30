#include<stdio.h>
double aveandsub_ptr(double *,double *,double *);
int main()
{
    double a,b,c,ave;
    printf("3つの値を入力して下さい:\n");
    scanf("%lf%lf%lf",&a,&b,&c);
    ave=aveandsub_ptr(&a,&b,&c);

    printf("平均: %.3f\n",ave);
    printf("平均からの差分: %+.3f %+.3f %+.3f\n",a,b,c);
    return 0;
}

double aveandsub_ptr(double *p,double *q,double *r)
{
    double ave;
    ave=(*p+*q+*r)/3;
    *p=*p-ave;
    *q=*q-ave;
    *r=*r-ave;
    return ave;
}