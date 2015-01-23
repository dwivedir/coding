#include<iostream>
#include<stdio.h>
#include<vector>
#define N 50005
#define K 505
using namespace std;
long long sum = 0;
vector<int> adj[N];
long long dist[N][K];
void dfs(int cur, int parent, int k)
{
  long long bended = 0;
  dist[cur][0] = 1;
  for(unsigned i=0; i<adj[cur].size(); i++){
    if(adj[cur][i] != parent)
    {
      dfs(adj[cur][i],cur,k);
      for(int j=1; j<=k; j++)
        dist[cur][j] += dist[adj[cur][i]][j-1];
    }
  }
  for(unsigned i=0; i<adj[cur].size(); i++){
    if(adj[cur][i] != parent)
    {
      for(int j=1; j<k; j++)
        bended += dist[adj[cur][i]][j-1]*(dist[cur][k-j] - dist[adj[cur][i]][k-j-1]);
    }
  }
  sum += bended/2;
}

int main()
{
  int n, k;
  cin>>n>>k;
  for(int i=1; i<n; i++)
  {
    int a, b;
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,-1,k);

  for(int i=1; i<=n; i++){
    sum += dist[i][k];
  }

  cout<<sum;
  return 0;
}
