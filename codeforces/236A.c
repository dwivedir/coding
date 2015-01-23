#include<stdio.h>

int main()
{
  char str[150];
  int count[25] = {0};
  int i=0;
  gets(str);
  while(str[i] != '\0')
  {
    count[str[i] - 'a' ] ++;
    i++;
  }

  int sum = 0;
  for(i=0;i<25;i++)
    if(count[i] > 0)sum ++;

  if(sum & 1)
    puts("IGNORE HIM!");
  else
    puts("CHAT WITH HER!");

  return 0;

}
