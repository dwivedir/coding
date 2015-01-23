#include<stdio.h>
#include<stdlib.h>

int main()
{
  int l,i=0,k =0;
  char str[100], x = 'X';
  scanf("%d %s", &l, str);
  while(str[i] != '\0')
  {
    if(str[i] != x)
    {
      k++;
      x = str[i];
    }
    i++;
  }
  printf("%d", l-k);

  return 0;
}

