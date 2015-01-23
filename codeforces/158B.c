#include<stdlib.h>
#include<stdio.h>

int main()
{
  int x[5] = {0},i,n,val,min;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&val);
    x[val]++;
  }

  val = x[4] + x[3] + (x[2]+1)/2;
  x[2] %= 2;
  x[1] = x[1] - x[3] - 2 * x[2];
  if(x[1] > 0)
    val += (x[1] % 4 == 0)? x[1]/4 : (x[1]+4)/4;

  printf("%d", val);

  return 0;
}
