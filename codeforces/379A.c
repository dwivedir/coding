#include<stdio.h>
#include<stdlib.h>

int main()
{
  int x,y;
  scanf("%d%d", &x, &y);
  int sum = 0;
  while(x>0)
  {
    sum += x;
    x /= y;
  }

  printf("%d", sum);

  return 0;
}
