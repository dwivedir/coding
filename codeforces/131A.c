#include<stdio.h>
#include<string.h>

int isCap(char x)
{
  if(x>='A' && x<='Z')
    return 1;
  return 0;
}

int main()
{
  char str[150], invert[150];
  int i=0,l,caps=0;
  gets(str);
  l = strlen(str);
  while(str[i] != '\0')
  {
    if(isCap(str[i]))
    { 
      caps ++;
      invert[i] = str[i]+32;
    }
    else
      invert[i] = str[i] -32;
    i++;
  }
  invert[i] = '\0';
  if(caps == l || caps == l-1 && !isCap(str[0]))
    puts(invert);
  else
    puts(str);

  return 0;

}

