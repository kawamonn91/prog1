#include<stdio.h>
int main()
{
    int i;
    int array[]={11,22,33,44};
    float f_array[]={0.1,0.2,0.3,0.4};
    double d_array[]={1e+4,2e+3,3e+2,4e+1};
    char c_array[]={'A','B','C','D'};
    char c_2d_array[][9]={"ab","c","defg","hij"};
    char *str_array[]={"ab","c","defg","hij"};

    for(i=0;i<4;i++)
    printf("%d %p %d\n",i,&array[i],array[i]);
    for(i=0;i<4;i++)
    printf("%d %p %.1f\n",i,&f_array[i],f_array[i]);
    for(i=0;i<4;i++)
    printf("%d %p %f\n",i,&d_array[i],d_array[i]);
    for(i=0;i<4;i++)
    printf("%d %p %c\n",i,&c_array[i],c_array[i]);
    for(i=0;i<4;i++)
    printf("%d %p %s\n",i,&c_2d_array[i],c_2d_array[i]);
    for(i=0;i<4;i++)
    printf("%d %p %s\n",i,str_array[i],*str_array[i]);
    printf("\n%p\n",array);
    printf("Size of each type\n");
    printf(" int: %ld,  float: %ld,  double: %ld,  char: %ld\n", sizeof(int), sizeof(float), sizeof(double), sizeof(char));
    printf(" int*: %ld, float*: %ld, double*: %ld, char*: %ld\n", sizeof(int *), sizeof(float *), sizeof(double *), sizeof(char *));
    return 0;
}