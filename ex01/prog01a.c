#include<stdio.h>
int main()
{
  char c;
  printf("Input a character: ");
  scanf("%c",&c);
  printf("\n");

  printf("'%c': %d in Decimal /0x%x in Hexadecimal\n",c,c,c);

  return 0;
}
