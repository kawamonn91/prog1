#include<stdio.h>
#include<stdlib.h>
int main()
{
    int count=0;
    char c1,c2;
    FILE*fp1,*fp2;

    //ファイルを読み出し設定で開く
    if((fp1=fopen("output3.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: output3.txt\n");
        exit(1);
    }

    if((fp2=fopen("output3_sample.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: output3_sample.txt\n");
        fclose(fp1);
        exit(2);
    }

    while(1)
    {
        //読み取り結果をresultに格納
        int result1=fscanf(fp1,"%c",&c1);
        int result2=fscanf(fp2,"%c",&c2);

        //終了条件
        if((result1==EOF)&&(result2==EOF))
        {
            printf("Two files sre identical\n");
            break;
        }

        //文字数カウント
        count++;

        //文字が違った際の処理
        if(c1!=c2)
        {
            printf("%d番目の文字が異なります\n",count);
            break;
        }
    }

    //ファイルを閉じる
    fclose(fp1);
    fclose(fp2);

    return 0;
}