#include<bits/stdc++.h>
using namespace std;
#define N 1005
bool dp[N][N];
int n,m;
bool possible(int i, int j)
{
  if(i>=1 && i<=n && j>=1 && j<=m)
    return 1;
  return 0;
}
int main()
{
  int k;
  cin>>n>>m>>k;
  bool answered = 0;
  for(int i=1; i<=k; i++)
  {
    int x,y,r=0; 
    cin>>x>>y;
    dp[x][y] =1;
    if(possible(x,y-1) && dp[x][y-1] && possible(x-1,y-1) && dp[x-1][y-1] && possible(x-1,y) && dp[x-1][y])
      r++;
    if(possible(x,y-1) && dp[x][y-1] && possible(x+1,y-1) && dp[x+1][y-1] && possible(x+1,y) && dp[x+1][y])
      r++;
    if(possible(x,y+1) && dp[x][y+1] && possible(x+1,y+1) && dp[x+1][y+1] && possible(x+1,y) && dp[x+1][y])
      r++;
    if(possible(x,y+1) && dp[x][y+1] && possible(x-1,y+1) && dp[x-1][y+1] && possible(x-1,y) && dp[x-1][y])
      r++;
    if(r>0 && !answered){
      cout<<i;
      answered = 1;
    }
  }
  if(!answered)
    cout<<"0";
  return 0;
}
