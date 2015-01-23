#include<iostream>
#include<stdio.h>
#define N 105
#define mod 100000000
using namespace std;

long long dp[N][N][2];
int main()
{
  int n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;
  dp[0][0][0]= dp[0][0][1] = 1;
  for(int i=0; i<=n1; i++)
  {
    for(int j=0; j<=n2; j++)
    {
      if(i==0 && j==0) continue;
      dp[i][j][0] = dp[i][j][1] = 0;
      for(int l=1; l<=min(k1,i); l++){
        dp[i][j][0] += dp[i-l][j][1];
        dp[i][j][0] %= mod;
      }
      for(int l=1; l<=min(k2,j); l++){
        dp[i][j][1] += dp[i][j-l][0];
        dp[i][j][1] %= mod;
      }
    }
  }
  cout<<(dp[n1][n2][0]+dp[n1][n2][1])%mod;
  return 0;
}
