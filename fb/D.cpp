#include<bits/stdc++.h>
#define N 200005
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<int> adj[N];
map<int,ll>::iterator it;
map<int,ll> A;
struct node
{
  long long minFirst;
  long long minSecond;
  int color;
}gift[N];

void compute(int u,int n)
{
  A.clear();
  long long B = 0;
  for(unsigned i=0; i<adj[u].size(); i++)
  {
    int v = adj[u][i];
    B += gift[v].minFirst;
    if(A.find(gift[v].color) == A.end())
      A[gift[v].color] = gift[v].minSecond - gift[v].minFirst;
    else
      A[gift[v].color] += gift[v].minSecond - gift[v].minFirst;
  }
  int r = n - A.size();
  r= min(r,2);
  for(int i=1; i<=n && r >0; i++)
    if(A.find(i) == A.end()){
      A[i] = 0;
      r--;
    }
  ll min1 = INF;
  ll min2 = INF;
  for(it = A.begin(); it != A.end(); it++){
    ll sum = it->first + B + it-> second;
    if(sum<=min1){
      min2 = min1;
      gift[u].color = it->first;
      min1 = sum;
    }
    else if(sum<min2)
      min2 = sum;
  }
  gift[u].minFirst = min1;
  gift[u].minSecond = min2;

}

long long dfs(int n)
{
  stack<ii> list;
  list.push(ii(1,0));
  while(!list.empty())
  {
    ii it = list.top();
    list.pop();
    int u = it.first;
    int c = it.second;
    if(c>=adj[u].size())
    {
      compute(u,n);
      continue;
    }
    list.push(ii(u,c+1));
    int v = adj[u][c];
    list.push(ii(v,0));
  }
}
int main()
{
  int t,n;
  scanf("%d",&t);
  for(int k=1; k<=t; k++)
  {
    int p;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
      adj[i].clear();
    }
    for(int i=1; i<=n; i++)
    {
      scanf("%d",&p);
      adj[p].push_back(i);
    }
    dfs(n);
    long long ans = gift[1].minFirst;

    printf("Case #%d: %lld\n",k,ans);
  }
  return 0;
}
