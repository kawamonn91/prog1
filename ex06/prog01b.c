#include<stdio.h>
double aveandsub_arr(double[]);
int main()
{
    double data[3],ave;

    printf("3つの値を入力して下さい:\n");
    scanf("%lf%lf%lf",&data[0],&data[1],&data[2]);
    
    ave=aveandsub_arr(data);

    printf("平均: %.3f\n",ave);
    printf("平均からの差分: %+.3f %+.3f %+.3f\n",data[0],data[1],data[2]);
    return 0;
}

double aveandsub_arr(double data[])
{
    double ave,total=0;
    for(int i=0;i<3;i++)
    {
        total=total+data[i];
    }

    ave=total/3;
    
    for(int i=0;i<3;i++)
    {
        data[i]=data[i]-ave;
    }

    return ave;
}