#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    int count=0,lcount=0;
    FILE *fpin,*fpout;

    //ファイルを読み出し指定で開き、エラー処理
    if((fpin=fopen("input1.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: input1.txt\n");
        exit(1);
    }

    //ファイルを書き出し指定で開き、エラー処理
    if((fpout=fopen("output1.txt","w"))==NULL)
    {
        fprintf(stderr,"Failed to open: output1.txt\n");
        fclose(fpin);
        exit(2);
    }

    //ファイルの読み込み
    while(fscanf(fpin,"%c",&c)!=EOF)
    {
        printf("%c",c);
        //ファイルへの書き込み
        fprintf(fpout,"%c",c);
        count++;
        if(c=='\n') lcount++;
    }

    fprintf(stderr,"%d characters(%d lines) are read and copied.\n",count,lcount);

    //ファイルを閉じる
    fclose(fpin);
    fclose(fpout);

    return 0;
}