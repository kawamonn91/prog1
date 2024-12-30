#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char buf[1000],low[1000];
    int count=0,c='\n';
    FILE*fpin,*fpout;
    //ファイルを読み出し設定で開く
    if((fpin=fopen("input1.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: input1.txt\n");
        exit(1);
    }

    //ファイルを書き出し設定で開く
    if((fpout=fopen("output3.txt","w"))==NULL)
    {
        fprintf(stderr,"Failed to open: output3.txt\n");
        fclose(fpin);
        exit(2);
    }

    //ファイル書き込み
    for(int i=0;fscanf(fpin,"%c",&buf[i])!=EOF;i++)
    {
        if(i>1000) 
        {
            printf("bufの容量をオーバーしてます\n");
            break;
        }
        fprintf(fpout,"%c",buf[i]);
        count++;
    }
    fputc(c,fpout);

    //ファイルをいったん閉じる
    fclose(fpout);

    //ファイルを追記設定で開く
    if((fpout=fopen("output3.txt","a"))==NULL)
    {
        fprintf(stderr,"Failed to open: output3.txt\n");
        fclose(fpin);
        exit(3);
    }

    //bufを小文字化
    for(int i=0;buf[i]!='\0';i++)
    {
        low[i]=tolower(buf[i]);
    }
    low[count]='\0';


    //ファイル書き込み
    for(int i=0;i<=count-1;i++)
    {
        fprintf(fpout,"%c",low[i]);
    }

    //ファイルに逆順で書き込み
    for(int i=count-1;i>=0;i--)
    {
        fprintf(fpout,"%c",buf[i]);
    }
    fputc(c,fpout);

    //ファイルを閉じる
    fclose(fpin);
    fclose(fpout);

    return 0;
}