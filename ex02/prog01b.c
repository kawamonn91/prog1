#include<stdio.h>
void seqaverage_global(double data);
int cnt=0;
double avg=0;
int main()
{
    double data;
     while(1)
    {
        printf("入力データ:");
        if(scanf("%lf",&data)!=1) break;
        cnt++;
        seqaverage_global(data);
        printf("データ数:%d,平均:%.6f\n",cnt,avg);
    }

    printf("最終結果はデータ数%dで、平均値%.6fでした\n",cnt,avg);
    return 0;
}

void seqaverage_global(double data)
{
    avg=((cnt-1)*avg+data)/cnt;
}