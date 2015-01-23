#include<stdio.h>
#include<stdlib.h>

char lower(char x)
{
  if(x>='A' && x <= 'Z')
    return x + 32;
  return x;
}

int compare(char x, char y)
{
  x = lower(x);
  y = lower(y);

  if(x < y) return -1;
  else if(x == y) return 0;
  else return 1;
}


int main()
{
  char str1[150], str2[150];
  gets(str1);
  gets(str2);
  int i = 0;
  while(str1[i] != '\0')
  {
    if(compare(str1[i], str2[i]) != 0)
      break;
    i++;
  }

  printf("%d",compare(str1[i], str2[i]));

  return 0;

}

