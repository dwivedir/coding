#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i= 0, ans = 0;
  char str[150];
  gets(str);
  while(str[i] != '\0')
  {
    if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
    {
      ans = 1;
      break;
    }
    i++;
  }

  if(ans)
    puts("YES");
  else
    puts("NO");

  return 0;
}
