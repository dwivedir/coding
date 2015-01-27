#include<iostream>
#include<stdio.h>
typedef long long ll;
using namespace std;
#define N 1005

ll base[N];
ll dp[N][105];
ll power(ll x, ll n, ll mod)
{
  ll y = 1;
  x %= mod;
  while(n>0)
  {
    if(n&1)
      y = (y*x)%mod;
    x = (x*x)%mod;
    n >>= 1;
  }
  return y;
}

int main()
{
  int n,k,m;
  cin>>n>>k>>m;
  base[n] = 1;
  for(int i=1; i<n; i++)
    base[i] = ((ll)9 * power(10,n-i-1,m))%m;

  for(int j=0; j<k; j++)
    dp[n][j] = 0;
  for(int i=n-1; i>0; i--)
  {
    for(int j=1; j<k; j++)
    {
      dp[i][j] = 0;
      for(int x=0; x<10; x++)
      {
        int y = (j+ x*power(10,i,k))%k;
        if(!y)
          dp[i][j] = (dp[i][j] + base[i+1])%m;
        else
          dp[i][j] = (dp[i][j] + dp[i+1][y])%m;
      }
    }
    dp[i][0] = 0; // repesents the contribution of suffix zero
    dp[i][0] = (dp[i][0] + dp[i+1][0])%m;
    for(int x=1; x<10; x++)
    {
      int y = (x*power(10,i,k))%k;
      if(!y) 
        dp[i][0] = (dp[i][0] + base[i+1])%m;
      else
        dp[i][0] = (dp[i][0] + dp[i+1][y])%m;
    }
  }
  /*for(int i=1; i<=n; i++)
  {
   for(int j=0; j<k; j++)
    cout<<dp[i][j]<<" ";
   cout<<endl;
  }*/ 
  ll ans = 0;
  for(int x=0; x<10; x++){
    if(x==0)
    ans = (ans + dp[1][0])%m;
    else if(x%k == 0)
      ans = (ans + base[1])%m;
    else
      ans = (ans + dp[1][x%k])%m;
  }
  cout<<ans; 
  return 0;
}
