#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int index(char str[], int x, char c)
{
  for(int i=x; i<=strlen(str+1); i++)
  {
    if(str[i] == c)
      return i;
  }
  return -1;
}

int main()
{
  char sample[10] = "Ohello", str[150];
  gets(str+1);
  int x=1;
  for(int i = 1; i<= 5; i++)
  {
    x = index(str,x, sample[i]);
    if(x == -1)
      break;
    x++;
  }

  if(x>0)
    puts("YES");
  else
    puts("NO");

  return 0;

}

