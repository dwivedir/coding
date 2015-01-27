#include<bits/stdc++.h>
using namespace std;
char str[100005];
int main()
{
  cin>>(str+1);
  int j = -1,l = strlen(str+1);
  char x = str[l];
  for(int i=1; str[i]; i++)
  {
    int y = str[i]-'0';
    if(y % 2 == 0)
    {
      j = i;
      if(str[i] < x)
        break;
    }
  }
  if(j == -1)
    cout<<j;
  else {
    char temp = str[j];
    str[j] = x;
    str[l] = temp;
    cout<<(str+1);
  }
  return 0;
}
