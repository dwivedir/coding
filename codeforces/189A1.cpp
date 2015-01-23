#include<iostream>
#include<stdio.h>
using namespace std;

int dp[4005];
int main()
{
  int n,a,b,c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  dp[0] = 0;
  for(int i =1; i<=n; i++)
  {
    if(i<a && i<b && i<c)
      dp[i] = -1;
    else
    {
      dp[i] = -1;
      if(i-a>=0)
        dp[i] = max(dp[i],dp[i-a]);
      if(i-b>=0)
        dp[i] = max(dp[i],dp[i-b]);
      if(i-c>=0)
        dp[i] = max(dp[i],dp[i-c]);
      if(dp[i]>=0)
        dp[i] += 1;
    }
    //cout<<dp[i] << endl;
  }
  cout << dp[n]; 
  return 0;
}
