#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int m,n,cost[10];
  cin>>m>>n;
  for(int i=1; i<=n; i++)
  {
    cost[i] = 0;
  }

  int x;
  while(m--)
  {
    cin>>x;
    cost[1] += x;
    for(int i=2; i<=n; i++)
    {
      cin>>x;
      if(cost[i] < cost[i-1]) cost[i] = cost[i-1];
      cost[i] += x;
    }

    cout<<cost[n]<<" ";
  }

  return 0;

}
