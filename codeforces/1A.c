#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m,a;
  long long l,b;
  scanf("%d%d%d", &n,&m,&a);
  if(n%a == 0)
    l = n/a;
  else
    l = (n+a)/a;

  if(m%a == 0)
    b = m/a;
  else
    b = (m+a)/a;

  printf("%lld", l*b);

  return 0;
}
