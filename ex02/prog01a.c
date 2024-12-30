#include<stdio.h>
double seqaverage(double preave,double data,int n);
int main()
{
    double average=0,data=0;
    int n=0;

    while(1)
    {
        printf("入力データ: ");
        if(scanf("%lf",&data)!=1) break;
        n++;
        printf("n=%d",n);
        average=(seqaverage(average,data,n));
        printf("データ数:%d, 平均:%.6f\n",n,average);
    }

    printf("最終結果はデータ数%dで、平均値%.6fでした\n",n,average);
    return 0;
}

double seqaverage(double preave,double data,int n)
{
    double average;
    average=(preave*(n-1)+data)/n;
    return average;
}