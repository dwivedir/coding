#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char str[150];
  int i,l,x[4] = {0};
  gets(str+1);
  l = strlen(str+1);
  for(i=1; i<=l; i+=2)
  {
    x[str[i] - '0'] ++;
  }

  i = 0;
  while(x[1] --)
  {
    str[i] = '1'; str[i+1] = '+';
    i+=2;
  }
  while(x[2] --)
  {
    str[i] = '2'; str[i+1] = '+';
    i+=2;
  }
  while(x[3] --)
  {
    str[i] = '3'; str[i+1] = '+';
    i+=2;
  }
  str[i-1] = '\0';
  puts(str);

  return 0;

}
