#define N 600000
typedef struct 
{
    int data[N];
    int count[6];
}DiceRollData;


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void ComputeStatisticsPtr(DiceRollData*);
DiceRollData ComputeStatisticsV(DiceRollData);
int main()
{
    DiceRollData data;
    time_t start,end;
    double time1,time2;
    //乱数の種を作る
    srand((unsigned int)time(NULL));
    //配列の初期化
    for(int i=0;i<6;i++)
    {
        data.count[i]=0;
    }
    //乱数を格納
    for(int i=0;i<N;i++)
    {
        data.data[i]=rand()%6;
    }

    
    printf("ComputeStatisticsPtr\n");
    //計測開始
    start=clock();
    //ポイント渡しの関数による構造体の操作
    ComputeStatisticsPtr(&data);
    //計測終了
    end=clock();
    time1=(end-start)/(double)CLOCKS_PER_SEC;
    for(int i=0;i<6;i++)
    {
        printf("[%d]:%d\n",i,data.count[i]);
    }
    printf("\n");
    //配列の初期化
    for(int i=0;i<6;i++)
    {
        data.count[i]=0;
    }
    //乱数の格納
    for(int i=0;i<N;i++)
    {
        data.data[i]=rand()%6;
    }
    printf("ComputeStatisticsV\n");
    //計測開始
    start=clock();
    //値渡しの関数による構造体の操作
    data=ComputeStatisticsV(data);
    //計測終了
    end=clock();
    time2=(end-start)/(double)CLOCKS_PER_SEC;
    for(int i=0;i<6;i++)
    {
        printf("[%d]:%d\n",i,data.count[i]);
    }
    printf("---time---\n");
    printf("Call by address:%.6f sec\n",time1);
    printf("Call by value:%.6f\n",time2);
    return 0;
}

void ComputeStatisticsPtr(DiceRollData *data)
{
    for(int i=0;i<N;i++)
    {
        switch(data->data[i])
        {
            case 0:
                data->count[0]++;
                break;

            case 1:
                data->count[1]++;
                break;

            case 2:
                data->count[2]++;
                break;

            case 3:
                data->count[3]++;
                break;

            case 4:
                data->count[4]++;
                break;

            case 5:
                data->count[5]++;
                break;
            
        }
    }
}

DiceRollData ComputeStatisticsV(DiceRollData data)
{
     for(int i=0;i<N;i++)
    {
        switch(data.data[i])
        {
            case 0:
                data.count[0]++;
                break;

            case 1:
                data.count[1]++;
                break;

            case 2:
                data.count[2]++;
                break;

            case 3:
                data.count[3]++;
                break;

            case 4:
                data.count[4]++;
                break;

            case 5:
                data.count[5]++;
                break;
            
        }
    }
    return data;
}