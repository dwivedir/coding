#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char str[150];
  int i,n,l;
  scanf("%d", &n);
  for( i = 1;  i<=n; i++)
  {
    scanf("%s", str+1);
    l = strlen(str+1);
    if(l<=10)
      puts(str+1);
    else
      printf("%c%d%c\n",str[1],l-2,str[l]);
  }

  return 0;
}
