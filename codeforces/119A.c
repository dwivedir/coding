#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
  if( a == 0) return b;
  else
    return gcd(b%a, a);
}

int main()
{
  int a,b,n,count=0;
  scanf("%d%d%d", &a, &b, &n);
  while(n>0)
  {
    if(count == 0)
      n -= gcd(n,a);
    else
      n -= gcd(n,b);
    count = 1-count;
  }

  printf("%d", 1-count);

  return 0;
}
