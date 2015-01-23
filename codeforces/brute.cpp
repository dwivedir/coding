#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  int x, y;
  cin>>x>>y;
  int ans = 0;
  for(int i=x; i<=y; i++)
    for(int j=i+1; j<=y;j++)
    {
      if((i ^ j)>ans)
        ans = i ^ j;
    }

  cout<<ans;
  return 0;
}
