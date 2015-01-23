#include<stdio.h>
#include<stdlib.h>

int main()
{
  char x = 'a', str[150];
  int i=0, count, max = -1;
  gets(str);
  while(str[i] != '\0')
  {
    if(str[i] != x)
    {
      count = 1;
      x = str[i];
    }
    else
      count ++;
    if(count > max) max = count;
    i++;
  }

  if(max >= 7)
    puts("YES");
  else
    puts("NO");

  return 0;
}
