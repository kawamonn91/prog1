#include <stdio.h>
#define TRUE 1
#define FALSE 0
int isUpper(char c);
int isAlpha(char c);
int main()
{
  char c;
  printf("Input any characters: ");
  while(1)
    {
      scanf("%c",&c);
      if(c=='\n') break;
      printf("'%c': %4d in Decimal / 0x%x in Hexadecimal. ",c,c,c);
      if(isAlpha(c))
	{
	  if(isUpper(c)) printf("It's an upper-case character.\n");
	  else printf("It's a non-upper character.\n");
	}
	  
      else  printf("It's non-alphabetic charqacter.\n");
    }

      return 0;
}

  int isAlpha(char c)
  {
    if((c>=65&&c<=90)||(c>=97&&c<=122)) return TRUE;
    else return FALSE;
  }

  int isUpper(char c)
  {
    if(c>=65&&c<=90) return TRUE;
    else return FALSE;
  }
  
  
