#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
    int num,max=0,min=INT_MAX,sum=0,count=0;
    double ave;
    FILE*fpin,*fpout;
    //ファイルを読み出し指定で開き、エラー処理をする
    if((fpin=fopen("input2.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: input2.txt\n");
        exit(1);
    }

    //ファイルを書き込み指定で開き、エラー処理
    if((fpout=fopen("result2.txt","w"))==NULL)
    {
        fprintf(stderr,"Failed to open: result2.txt\n");
        fclose(fpin);
        exit(2);
    }

    while(fscanf(fpin,"%d",&num)!=EOF)
    {
        if(num>max) max=num;
        if(num<min) min=num;
        sum=sum+num;
        count++;
    }
    //平均値の計算
    ave=(double)sum/count;

    //ファイルへの書き込み
    fprintf(fpout,"max = %d, min = %d,average=%.6f\n",max,min,ave);

    //ファイルを閉じる
    fclose(fpin);
    fclose(fpout);

    return 0;
}