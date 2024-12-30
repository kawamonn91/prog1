#include <stdio.h>
#define TRUE 1
#define FALSE 0
int isAlpha(char c);
int main()
{
  char c;

  printf("Input any characters: ");

  while(1)
    {
      scanf("%c",&c);
      if(c=='\n') break;
      printf("'%c': %4d in Decimal / 0x%x in Hexadeciaml. ",c,c,c);
      if(isAlpha(c)) printf("It's an alphabetic character\n");
      else printf("It's a non-alphabetic character\n");
    }

  return 0;
}

int isAlpha(char c)
{
  if((c>=65&&c<=90)||(c>=97&&c<=122)) return TRUE;
  else return FALSE;
}
  
