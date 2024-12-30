#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fp;
    char code[4],airport[30];
    char buf[4];
    

    while(1)
    {
        int status=0;
        printf("Input IATA code:");
        if(scanf("%s",buf)==EOF) break;

        //ファイルを読み出し指定で開く
        if((fp=fopen("IATA-jp.txt","r"))==NULL)
        {
            printf("Code file open error!!\n");
            exit(2);
        }

        while(1)
        {
            fscanf(fp,"%s",code);
            fscanf(fp,"%s",airport);
            if(strcmp(buf,code)!=0) status=0;
            else if(strcmp(buf,code)==0)
            {
                status=1;
                break;
            } 

            if(feof(fp)) break;
        }
        //ファイルを閉じる
        fclose(fp);

        if(status==1) printf("%s is %s Airport\n",code,airport);
        if(status==0) printf("%s is not found\n",buf);
    }
    printf("\n");
    return 0;
}