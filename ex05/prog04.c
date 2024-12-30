#include <stdio.h>
 
#define N 6
 
int main()
{
  int data[N];     /* 配列の宣言 */
  int tmp;
  int *p,*q,*max_ptr;
  
  printf("Please input %d numbers\n",N);
  //配列の格納
  for(p=&data[0];p<(data+N);p++)
  {
    scanf("%d",p);
  }
  //sort

  for(p=&data[0];p<(data+N);p++)
  {
    max_ptr=p;
    for(q=p+1;q<data+N;q++)
    {
        //最大値の更新
        if(*q>*max_ptr) max_ptr=q;
    }
    //入れ替え
    if(max_ptr!=p)
    {
        tmp=*p;
        *p=*max_ptr;
        *max_ptr=tmp;
    }
  }

  printf("Sorted data from highest to lowest\n");
  for(p=&data[0];p<data+N;p++)
  {
    printf("%d  ",*p);
  }
  printf("\n");
  return 0;
} 