#include<stdio.h>

int main()
{

  int n,i,x,y,z,ans=0,count;
  scanf("%d", &n);
  for(i = 1; i<=n; i++)
  {
    count = 0;
    scanf("%d%d%d", &x, &y, &z);
    if(x) count++;
    if(y) count++;
    if(z) count++;

    if(count >=2) ans++;
  }

  printf("%d",ans);
  return 0;
}
