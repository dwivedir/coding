#include<stdlib.h>
#include<stdio.h>


char lower(char x)
{
  if(x>='A' && x <= 'Z')
    x += 32;
  return x;
}

int isvowel(char x)
{
  if(x == 'a' || x == 'o' || x == 'y' || x == 'e' || x == 'u' || x == 'i')
    return 1;
  return 0;
}

int main()
{
  char str[150];
  int i=0;
  char x;
  gets(str);
  while(str[i] != '\0')
  {
    x = lower(str[i]);
    if(!isvowel(x))
    {
      printf(".%c",x);
    }
    i++;
  }

  return 0;
}
