#include<stdio.h>
#include<stdlib.h>

int differ(int n)
{
  int y[10] = {0},i;
  while(n>0)
  {
    y[n%10]++;
    n /= 10;
  }
  for(i=0;i<=9;i++)
  {
    if(y[i] > 1)
    {
      return 0;
    }
  }
  return 1;
}
int main()
{
  int n;
  scanf("%d", &n);
  while(1)
  {
    ++n;
    if(differ(n))
    {
      printf("%d",n);
      break;
    }
  }

  return 0;
}
