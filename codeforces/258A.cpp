#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
  char str[100005],ans[100005];
  int position = -1;
  cin >> str;
  for(int i=0; str[i]; i++)
  {
    if(str[i] == '0')
    {
      position = i;
      break;
    }
  }
  int l = strlen(str);
  if(position == -1)
  {
    str[l-1] = '\0';
    puts(str);
  }
  else
  {
    for(int i=0; i<l; i++)
    {
      if(i == position)
        continue;
      else
        cout<< str[i];
    }
  }

  return 0;
}
