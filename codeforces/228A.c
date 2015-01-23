#include<stdio.h>

int main()
{
  int x[5],i,j;
  for(i=1;i<=4;i++)
    scanf("%d", &x[i]);

  for(i=1;i<4;i++)
    for(j=1;j<4;j++)
    {
      if(x[j] > x[j+1])
      {
        int temp = x[j];
        x[j] = x[j+1];
        x[j+1] = temp;
      }
    }

  int change = -1,count =0;
  for(i=1;i<=4;i++)
  {
    if(change != x[i])
    {
      change = x[i];
      count++;
    }
  }

  printf("%d", 4-count);

  return 0;
}
