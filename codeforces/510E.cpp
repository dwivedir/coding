#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 205
int Graph[N][N];
int A[N];
bool notprime[100005];
bool bfs(int n,int *parent)
{
  int source = 0;
  int sink = n+1;
  bool visited[N];
  memset(visited,0,sizeof(visited));
  queue<int> q;
  q.push(source);
  visited[source] = true;
  parent[source] = -1;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int v=0; v<=n+1; v++)
    {
      if(!visited[v] && Graph[u][v] >0)
      {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  return (visited[sink] == true);
}

int ford(int n)
{
  int source = 0;
  int sink = n+1;
  int parent[N];
  int max_flow = 0;

  while(bfs(n,parent))
  {
    int path_flow = INT_MAX;
    for(int i = sink; i!= source; i = parent[i])
    {
      path_flow = min(path_flow,Graph[parent[i]][i]);
    }
    for(int i = sink; i!=source; i = parent[i])
    {
      int v = parent[i];
      Graph[i][v] += path_flow;
      Graph[v][i] -= path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;

}

void makeGraph(int n)
{
  memset(Graph,0,sizeof(Graph));
  for(int i=1; i<=n; i++)
    if(A[i] %2 == 0)
      Graph[0][i] = 2;
  for(int i=1; i<=n; i++)
    if(A[i]&1)
      Graph[i][n+1] = 2;
  for(int i=1; i<=n; i++)
  {
    if(A[i] %2 == 0)
      for(int j=1; j<=n; j++)
      {
        if( A[j]&1 && !notprime[A[i] + A[j]]) //condition for edge betweeen the two
          Graph[i][j] = 1;
      }
  }
}
void printGraph(int n)
{
  for(int i=0; i<=n+1; i++)
  {
    for(int j=0; j<=n+1; j++)
      cout<<Graph[i][j]<<","<<Graph[j][i] <<" ";
    cout<<endl;
  }
}

int main()
{
  notprime[1] = notprime[0] = true;
  for(long long i = 2; i<=1e5; i++)
  {
    if(!notprime[i])
    {
      for(long long j=i*i; j<=1e5; j+=i)
        notprime[j] = true;
    }
  }
  int n,evenCount = 0;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>A[i];
    if(A[i] % 2 == 0)
      evenCount++;
  }
  makeGraph(n);
  //printGraph(n);
  int ans = ford(n);
  //cout<<endl;
  //printGraph(n);
  if(ans != 2*evenCount)
  {
    cout<<"Impossible";
    return 0;
  }
  int table = 0;
  int visited[n+5];
  memset(visited,0,sizeof(visited));
  vector<int> list[n];
  for(int i=1; i<=n; i++)
  {
    if(visited[i])continue;
    table++;
    int current = i;
    while(!visited[current])
    {
      //cout<<"current ="<<current<<"table = "<<table<<endl;
      list[table].push_back(current);
      visited[current] = 1;
      if(A[current]&1)
      {
        for(int j=1; j<=n; j++)
          if(!visited[j] && Graph[current][j] == 1)
          {
            current = j;
            break;
          }
      }
      else
      {
        for(int j=1; j<=n; j++)
          if(!visited[j] && Graph[j][current] == 1)
          {    
            current = j;
            break;
          }
      }
    }
  }
  cout<<table<<endl;
  for(int i=1; i<=table; i++)
  {
    cout<<list[i].size()<<" ";
    for(int j=0; j<list[i].size();j++)
      cout<<list[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
