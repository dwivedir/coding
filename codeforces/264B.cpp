#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> divisor[100005];

bool is_prime[100005];
int main()
{
  int d[100005],x;
  for(int i=1; i<=1e5; i++)
    d[i] = -1;

  for(int i=2; i<=1e5; i++)
  {
    if(!is_prime[i])
    {
      for(int j = i; j<=1e5; j+=i)
      {
        is_prime[j] = 1;
        divisor[j].push_back(i);
      }
    }
  }

  int n,dp[100005];
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>x;
    int length = -1;
    for(unsigned j=0; j<divisor[x].size(); j++)
    {
      if(d[divisor[x][j]] > length)
        length = d[divisor[x][j]];
    }
    dp[i] = (length == -1)? 1 : length +1;
    for(unsigned j=0; j<divisor[x].size(); j++)
      if(d[divisor[x][j]] < dp[i]) 
        d[divisor[x][j]] = dp[i];
  }


  int ans = -1;
  for(int i=1; i<=n; i++)
    if(dp[i] > ans)
      ans = dp[i];

  cout<<ans;

  return 0;

}
