#include<stdio.h>
#include<stdlib.h>

int main()
{
  int w;
  scanf("%d", &w);
  if(w&1 == 1 || w < 4)
    printf("NO");
  else
    printf("YES");

  return 0;
}
