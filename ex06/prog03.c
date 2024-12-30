#include<stdio.h>
#include<stdlib.h>
int main()
{
    double a,b,c,*array_1,*array_2;
    int size;
    printf("最初の値、最後の値、個数を入力:");
    scanf("%lf %lf %d",&a,&b,&size);
    c=(b-a)/(double)(size-1);
    //printf("a=%f,b=%f,c=%f,size=%d\n",a,b,c,size);
     //配列の作成
    array_1=(double *)malloc(size * sizeof(double));
    array_2=(double *)malloc(size * sizeof(double));
    //公差の計算
    c=(b-a)/(double)(size-1);

    //配列に格納
    for(int i=0;i<size;i++)
    {
        array_1[i]=a+c*i;
        array_2[i]=(a+c*i)*2;
    }
    //配列の表示
    printf("数値の列\n");
    for(int i=0;i<size;i++)
    {
        printf("%.3f",array_1[i]);
        if(i!=size-1) printf(" ");
    }
    printf("\n");

    printf("2倍値\n");
    for(int i=0;i<size;i++)
    {
        printf("%.3f",array_2[i]);
        if(i!=size-1) printf(" ");
    }
    printf("\n");
    //配列の開放
    free(array_1);
    free(array_2);
    return 0;
}