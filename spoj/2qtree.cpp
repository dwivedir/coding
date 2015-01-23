#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define root 1
#define N 10100
#define LN 14

vector<int> adj[N],cost[N],index[N];
int baseArray[N],treePoint[N],ptr;
int chainNo,chainInd[N],chainHead[N],posInBase[N];
int depth[N],pa[LN][N],otherEnd[N],subSize[N];
int st[N*6];

void make_tree(int cur, int p, int q)
{
  if(q<p)return;
  if(p==q)
  {
    st[cur] = baseArray[p];
    return;
  }
  int mid = (p+q)/2;
  make_tree(2*cur,p,mid);
  make_tree(2*cur+1,mid+1,q);
  st[cur] = st[2*cur]+st[2*cur+1];
}

int query_tree(int cur, int p, int q, int l, int r)
{
  if(p==l && q==r)
    return st[cur];
  int mid = (p+q)/2;
  if(mid<l)
    return query_tree(2*cur+1,mid+1,q,l,r);
  else if(mid>=r)
    return query_tree(2*cur,p,mid,l,r);
  else
    return query_tree(2*cur,p,mid,l,mid)+query_tree(2*cur+1,mid+1,q,mid+1,r);
}

int LCA(int u, int v)
{
  if(depth[u]<depth[v]) swap(u,v);
  int diff = depth[u] - depth[v];
  for(int i=0; i<LN; i++)
    if((diff>>i)&1) u = pa[i][u];
  if(u==v) return u;
  for(int i=LN-1; i>=0; i--)
    if(pa[i][u]!=pa[i][v])
    {
      u = pa[i][u];
      v = pa[i][v];
    }
  return pa[0][u];
}

int query1_up(int u, int v)
{
  if(u==v) return 0;
  int uchain,vchain = chainInd[v],ans = 0;
  while(1)
  {
    uchain = chainInd[u];
    if(uchain == vchain)
    {
      if(u==v)break;
      ans += query_tree(1,1,ptr-1,posInBase[v]+1,posInBase[u]);
      break;
    }
    ans += query_tree(1,1,ptr-1,posInBase[chainHead[uchain]],posInBase[u]);
    u = chainHead[uchain];
    u = pa[0][u];
  }
  return ans;
}

int query2_up(int u, int v)
{
  if(u==v) return 1;
  int uchain, vchain = chainInd[v], ans = 0;
  while(1)
  {
    uchain = chainInd[u];
    if(uchain == vchain)
    {
      ans += posInBase[u] - posInBase[v] + 1;
      break;
    }
    ans += posInBase[u] - posInBase[chainHead[uchain]] + 1;
    u = chainHead[uchain];
    u = pa[0][u];
  }
  return ans;
}

void query3_up(int u, int v, int k)
{
  int uchain, vchain = chainInd[v];
  bool answered = 0;
  while(!answered)
  {
    uchain = chainInd[u];
    int nodes = posInBase[u] - posInBase[chainHead[uchain]] + 1;
    if(nodes>=k)
    {
      int index = posInBase[u] -k + 1;
      printf("%d\n",treePoint[index]);
      answered = 1;
    }
    else
    {
      k -= nodes;
      u = chainHead[uchain];
      u = pa[0][u];
    }
  }
}

void query1(int u, int v)
{
  int lca = LCA(u,v);
  int ans = query1_up(u,lca);
  int temp = query1_up(v,lca);
  ans += temp;
  printf("%d\n",ans);
}

void query2(int u, int v, int k)
{
  int lca = LCA(u,v);
  int l1 = query2_up(u,lca);
  int l2 = query2_up(v,lca);
  if(l1>=k)
    query3_up(u,lca,k);
  else
  {
    k = k - l1 + 1;
    k = l2 - k + 1;
    query3_up(v,lca,k);
  }
}

void HLD(int curNode, int _cost, int prev)
{
  if(chainHead[chainNo] == -1)
    chainHead[chainNo] = curNode;
  chainInd[curNode] = chainNo;
  posInBase[curNode] = ptr;
  treePoint[ptr] = curNode;
  baseArray[ptr++] = _cost;

  int sc = -1,ncost;
  for(int i=0; i<adj[curNode].size(); i++)
  {
    if(adj[curNode][i] != prev)
      if(sc == -1 || subSize[sc] < subSize[adj[curNode][i]])
      {
        sc = adj[curNode][i];
        ncost = cost[curNode][i];
      }
  }
  if(sc != -1)
    HLD(sc,ncost,curNode);

  for(int i=0; i<adj[curNode].size(); i++)
    if(adj[curNode][i] != prev && sc != adj[curNode][i])
    {
      chainNo++;
      HLD(adj[curNode][i],cost[curNode][i],curNode);
    }
}

void dfs(int cur, int prev, int _depth)
{
  pa[0][cur] = prev;
  depth[cur] = _depth;
  subSize[cur] = 1;
  for(int i=0; i<adj[cur].size(); i++)
  {
    if(adj[cur][i] != prev)
    {
      dfs(adj[cur][i],cur, _depth+1);
      subSize[cur] += subSize[adj[cur][i]];
    }
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    ptr = 1;
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
      adj[i].clear();
      cost[i].clear();
      chainHead[i] = -1;
      for(int j=0; j<LN; j++)
        pa[j][i] = -1;
    }
    for(int i=1; i<n; i++)
    {
      int u,v,c;
      scanf("%d%d%d",&u,&v,&c);
      adj[u].push_back(v);
      cost[u].push_back(c);
      adj[v].push_back(u);
      cost[v].push_back(c);
    }

    chainNo = 1;
    dfs(root,-1,0);
    HLD(root,-1,-1);
    make_tree(1,1,ptr-1);

    for(int i=1; i<LN; i++)
      for(int j = 1; j<=n; j++)
        if(pa[i-1][j] != -1)
          pa[i][j] = pa[i-1][pa[i-1][j]];

    while(1)
    {
      char s[100];
      scanf("%s",s);
      if(s[1]=='O') break;
      int a, b,k;
      if(s[1]=='I'){
        scanf("%d%d",&a,&b);
        query1(a,b);
      }
      else{
        scanf("%d%d%d",&a,&b,&k);
        query2(a,b,k);
      }
    }
  }
}

