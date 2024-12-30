#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 6
#define COL 10

int main()
{
    int array[ROW][COL];
    int n=0,data,i,j,count=0;

    srand((unsigned int)time(NULL));
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            array[i][j]=rand()%100;
        }
    }


    printf("数値を入力して下さい:");
    scanf("%d",&data);

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d",array[i][j]);
            if(array[i][j]<=data) 
            {
                printf("**");
                n++;
            }

            else printf(" ");
        }
        printf("\n");
    }

    printf("%d以下の値は%d個ありました\n",data,n);
}