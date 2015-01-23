#include<stdio.h>
#include<stdlib.h>

int main()
{
  int positive =0, negative =0, n, i;
  char str[10];
  scanf("%d", &n);
  for(i=1;i<=n;i++)
  {
    scanf("%s",str);
    if(str[1] == '+')positive ++;
    else negative ++;
  }

  printf("%d", positive - negative);

  return 0;
}
