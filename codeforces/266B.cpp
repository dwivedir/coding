#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
  int n,t;
  char str[100];
  scanf("%d%d%s", &n, &t , str+1);
  while(t--)
  {
    for(int i=1; i+1<=strlen(str+1); i++)
    {
      if(str[i] == 'B' && str[i+1] == 'G')
      {
        str[i] = 'G';
        str[i+1] = 'B';
        i++;
      }
    }
  }

  puts(str+1);
  return 0;
}
