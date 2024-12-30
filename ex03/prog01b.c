#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char c1,c2='\n';
    int count=0;
    FILE*fpin,*fpout;

    if((fpin=fopen("input1.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: input1.txt\n");
        exit(1);
    }

    if((fpout=fopen("output1b.txt","w"))==NULL)
    {
        fprintf(stderr,"Failed to open: output1.txt\n");
        fclose(fpin);
        exit(2);
    }

    while(fscanf(fpin,"%c",&c1)!=EOF)
    {
        //ファイルへの書き込み
        fprintf(fpout,"%c",c1);
    }

    fprintf(fpout,"%c",c2);
    fclose(fpin);

    if((fpin=fopen("input1.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open: input1.txt\n");
        exit(1);
    }

    while(fscanf(fpin,"%c",&c1)!=EOF)
    {
        c1=toupper(c1);
        fprintf(fpout,"%c",c1);
    }

    return 0;
}