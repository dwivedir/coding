#include<stdio.h>
#include<stdlib.h>

char capital(char x)
{
  if(x>='a' && x <= 'z')
    x -= 32;
  return x;
}

int main()
{
  char str[1005];
  gets(str);
  str[0] = capital(str[0]);
  puts(str);

  return 0;

}

