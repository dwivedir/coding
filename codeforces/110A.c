#include<stdio.h>
#include<stdlib.h>

int is_lucky_char(char x)
{
  if( x == '4' || x == '7')
    return 1;
  return 0;
}

int is_lucky_int(int x)
{
  if(x == 4 || x == 7)
    return 1;
  return 0;
}

int is_lucky_num(int n)
{
  if(n == 0) return 0;
  int y;
  while(n>0)
  {
    y = n%10;
    n /= 10;
    if(!is_lucky_int(y))
      return 0;
  }
  return 1;
}
int main()
{
  char str[100];
  gets(str);
  int i=0,count=0;
  while(str[i] != '\0')
  {
    if(is_lucky_char(str[i]))count++;
    i++;
  }

  //printf("count = %d, %d ", count,is_lucky_num(count));

  if(!is_lucky_num(count))
    puts("NO");
  else
    puts("YES");

  return 0;
}
