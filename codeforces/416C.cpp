#include<iostream>
#include<stdio.h>
#define N 1100
using namespace std;

int dp[N][N];
char s[N][N];

int countRequest(int i, int j)
{
  if(i==0 || j==0)
    return 0;
  else if(s[i][j] == 'l')
    return countRequest(i,j-1);
  else if(s[i][j] == 'u')
    return countRequest(i-1,j);
  else
    return 1+countRequest(i-1,j-1);
}
void print(int i, int j)
{
  if(i==0 || j==0)
    return;
  else if(s[i][j] == 'l')
    print(i,j-1);
  else if(s[i][j] == 'u')
    print(i-1,j);
  else
  {
    print(i-1,j-1);
    printf("%d %d\n",i,j);
  }
}

int main()
{
  int n, C[N],P[N],k,R[N];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>C[i]>>P[i];
  cin>>k;
  for(int i=1; i<=k; i++)
    cin>>R[i];
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=k; j++)
    {
      dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
      if(dp[i][j] == dp[i][j-1]) s[i][j] = 'l';
      else s[i][j] = 'u';
      int x = dp[i][j];
      if(C[i]<=R[j]){
        dp[i][j] = max(dp[i][j] , P[i]+dp[i-1][j-1]);
        if(dp[i][j] != x)
          s[i][j] = 'm';
      }
    }
  }
  int count = countRequest(n,k);
  cout<<count<<" "<<dp[n][k]<<endl;
  print(n,k);
  return 0;
}
