#define SUBJECT_NUM 5
typedef struct 
{
    char id[10];
    char name[10];
    int score[SUBJECT_NUM];
    int sum;
    double ave;
    char grade;
}Record;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char score2Grade(int);
int main(int argc,char *argv[])
{
    Record data;
    FILE *fp;
    char input[10];
    int flag=0;
    //コマンドライン引数のチェック
    if(argc<2)
    {
        fprintf(stderr,"usage:%s filename\n",argv[0]);
        return 1;
    }
    //ファイルを開く
   if((fp=fopen(argv[1],"r"))==NULL)
    {
        fprintf(stderr,"file is not exist\n");
        return 2;
    }
    //ファイルの読み込み
    while(1)
    {
        if(feof(fp)) break;
        //IDの読み込み
        fscanf(fp,"%s",data.id);
        //名前の読み込み
        fscanf(fp,"%s",data.name);
        //点数の読み込み
        data.sum=0;
        for(int i=0;i<SUBJECT_NUM;i++)
        {
            fscanf(fp,"%d",&data.score[i]);
            //合計点の計算
            data.sum+=data.score[i];
        }
        //平均点の計算
        data.ave=(double)data.sum/SUBJECT_NUM;
        //判定
        data.grade=score2Grade(data.ave);
        //データの表示
        printf("%s %s ",data.id,data.name);
        for(int i=0;i<SUBJECT_NUM;i++)
        {
            printf("%d ",data.score[i]);
        }
        printf(" %d %.1f %c\n",data.sum,data.ave,data.grade);
    }

    while(1)
    {
        printf("Input a student name/ID:");
        if(scanf("%s",input)==EOF) break;
        while(1)
        {
            //IDを参照
            if((fp=fopen(argv[1],"r"))==NULL)
            {
                fprintf(stderr,"file is not exist\n");
                return 2;
            }
            while(1)
            {
                fscanf(fp,"%s",data.id);
                if(strcmp(data.id,input)==0)
                {
                    fscanf(fp,"%s",data.name);
                    //点数の読み込み
                    data.sum=0;
                    for(int i=0;i<SUBJECT_NUM;i++)
                    {
                        fscanf(fp,"%d",&data.score[i]);
                        //合計点の計算
                        data.sum+=data.score[i];
                    }
                    //平均点の計算
                    data.ave=(double)data.sum/SUBJECT_NUM;
                    //判定
                    data.grade=score2Grade(data.ave);
                    //データの表示
                    printf("%s %s ",data.id,data.name);
                    for(int i=0;i<SUBJECT_NUM;i++)
                    {
                        printf("%d ",data.score[i]);
                    }
                    printf(" %d %.1f %c\n",data.sum,data.ave,data.grade);
                    break;
                }
                if(feof(fp))
                {
                    flag=1;
                    break;
                }
            }
            //名前を参照
            if((fp=fopen(argv[1],"r"))==NULL)
            {
                fprintf(stderr,"file is not exist\n");
                return 2;
            }

            while(1)
            {
                strcpy(data.id,data.name);
                fscanf(fp,"%s",data.name);
                if(strcmp(input,data.name)==0)
                {
                    data.sum=0;
                    for(int i=0;i<SUBJECT_NUM;i++)
                    {
                        fscanf(fp,"%d",&data.score[i]);
                        //合計点の計算
                        data.sum+=data.score[i];
                    }
                    //平均点の計算
                    data.ave=(double)data.sum/SUBJECT_NUM;
                    //判定
                    data.grade=score2Grade(data.ave);
                    //データの表示
                    printf("%s %s ",data.id,data.name);
                    for(int i=0;i<SUBJECT_NUM;i++)
                    {
                        printf("%d ",data.score[i]);
                    }
                    printf(" %d %.1f %c\n",data.sum,data.ave,data.grade);
                    break;
                }
                if(feof(fp))
                    {
                        printf("This student does not exist\n");
                        break;
                    }
            }           
         break;
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}

char score2Grade(int score)
{
  if(score>=0&&score<=34) return 'F';
  if(score>=35&&score<=49) return 'D';
  if(score>=50&&score<=64) return 'C';
  if(score>=65&&score<=79) return 'B';
  if(score>=80&&score<=100) return 'A';
  return 'F';
}
