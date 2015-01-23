#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,a,b,i;
  int max = -1, ans = 0;
  scanf("%d", &n);
  for(i=1;i<=n;i++)
  {
    scanf("%d%d",&a,&b);
    ans += b -a;
    if(ans > max) max = ans;
  }

  printf("%d", max);
  return 0;
}
