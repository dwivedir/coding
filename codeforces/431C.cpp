#include<iostream>
#include<stdio.h>
#define mod 1000000007

using namespace std;

int main()
{
  int n,k,d;
  long long dp[101][2];

  cin>>n>>k>>d;
  dp[0][0] = 1;
  dp[0][1] = 0;
  for(int i=1; i<=n; i++)
  {
    dp[i][0] = dp[i][1] = 0;
    for(int j=1; j<=k; j++)
    {
      if(i-j>=0)
      {
        dp[i][0] += dp[i-j][0];
        dp[i][0] %= mod;
        if(j>=d)
          dp[i][1] += dp[i-j][0];
        else
          dp[i][1] += dp[i-j][1];
        dp[i][1] %= mod;
      }
    }
  }

  cout<< dp[n][1];

  return 0;
}
