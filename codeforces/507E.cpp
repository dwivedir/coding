#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> adj[N];
vector<bool> good[N];
int Max[N];
int dist1[N];
int distN[N];
int parent[N];
bool inpath[N];
struct node
{
  int from;
  int to;
  bool good;
}edge[N];
int main()
{
  int n,m,counter=0;
  bool visited[N];
  cin>>n>>m;
  int x,y,z;
  for(int i = 1; i<=m; i++){
    scanf("%d%d%d",&x,&y,&z);
    edge[i].from = x; edge[i].to = y; edge[i].good = z;
    adj[x].push_back(y);
    adj[y].push_back(x);
    good[x].push_back(z);
    good[y].push_back(z);
    counter += z;
  }
  queue<int> q;
  memset(visited,0,sizeof(visited));
  q.push(1);
  dist1[1] = 0;
  visited[1] = 1;
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(unsigned i=0; i<adj[x].size(); i++)
    {
      if(!visited[adj[x][i]])
      {
        visited[adj[x][i]] = 1;
        q.push(adj[x][i]);
        dist1[adj[x][i]] = dist1[x] + 1;
      }
    }
  }

  memset(visited,0,sizeof(visited));
  q.push(n);
  visited[n] = 1;
  distN[n] = 0;
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(unsigned i=0; i<adj[x].size(); i++)
    {
      if(!visited[adj[x][i]])
      {
        visited[adj[x][i]] = 1;
        q.push(adj[x][i]);
        distN[adj[x][i]] = distN[x] +1;
      }
    }
  }
  int d = dist1[n];
  memset(visited,0,sizeof(visited));
  q.push(1);
  visited[1] = 1;
  Max[1] = 0;
  
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(unsigned i=0; i<adj[x].size(); i++)
    {
      int v = adj[x][i];
      if(!visited[v] && dist1[v] + distN[v] == d)
      {
        visited[v] = 1;
        q.push(v);
        parent[v] = x;
        Max[v] = Max[x] + good[x][i];
      }
      else if(visited[v] && dist1[v] - dist1[x] == 1)
      {
        if(Max[v] < Max[x] + good[x][i]){
          Max[v] = Max[x] + good[x][i];
          parent[v] = x;
        }
      }
    }
  }
  cout<<counter+d-2*Max[n]<<endl;
  int node = n;
  inpath[1] = true;
  while(node != 1)
  {
    inpath[node] = 1;
    node = parent[node];
  }
  for(int i=1; i<=m; i++)
  {
    if(inpath[edge[i].to] && inpath[edge[i].from])
    {
      if(!edge[i].good)
        cout<<edge[i].from<<" "<<edge[i].to<<" 1\n";
    }
    else if(edge[i].good)
      cout<<edge[i].from<<" "<<edge[i].to<<" 0\n";
  }
  return 0;
}
