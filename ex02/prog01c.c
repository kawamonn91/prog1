#include<stdio.h>
double sequaverage_static(double data);
int main()
{
    int n=0;
    double data=0,avg=0;

    while(1)
    {
        printf("入力データ:");
        if(scanf("%lf",&data)!=1) break;
        n++;

        avg=sequaverage_static(data);
        printf("データ数%d, 平均.6f\n",data,avg);
    }

    printf("最終結果はデータ数%dで、平均値%.6fでした\n",n,avg);
    return 0;
} 

double sequaverage_static(double data);
{
    static double avg=0;
    static int n=0;
    n++;
    avg=(avg*(n-1)+data)/n;
    return avg;
}