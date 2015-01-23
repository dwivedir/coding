#include<stdio.h>
#include<stdlib.h>


int main()
{
  int n,m,i;
  scanf("%d%d", &n, &m);
  int days=0;
  while(n>0)
  {
    if(n<m)
    {
      days += n;
      break;
    }

    n -= m;
    days += m;
    ++n;
  }

  printf("%d",days);

  return 0;
}
