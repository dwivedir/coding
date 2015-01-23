#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define root 1
#define N 10100
#define LN 14

vector<int> adj[N],cost[N],index[N];
int baseArray[N],ptr;
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
  st[cur] = max(st[2*cur],st[2*cur+1]);
}

void update_tree(int cur, int p, int q, int x, int val)
{
  if(q<p)return;
  if(p==q)
  {
    st[cur] = val;
    return;
  }
  int mid = (p+q)/2;
  if(x>mid)
    update_tree(2*cur+1,mid+1,q,x,val);
  else
    update_tree(2*cur,p,mid,x,val);

  st[cur] = max(st[2*cur],st[2*cur+1]);
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
    return max(query_tree(2*cur,p,mid,l,mid),query_tree(2*cur+1,mid+1,q,mid+1,r));
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

int query_up(int u, int v)
{
  if(u==v) return 0;
  int uchain,vchain = chainInd[v],ans = -1;
  while(1)
  {
    uchain = chainInd[u];
    if(uchain == vchain)
    {
      if(u==v)break;
      ans = max(ans,query_tree(1,1,ptr-1,posInBase[v]+1,posInBase[u]));
      break;
    }
    ans = max(ans,query_tree(1,1,ptr-1,posInBase[chainHead[uchain]],posInBase[u]));
    u = chainHead[uchain];
    u = pa[0][u];
  }
  return ans;
}


void query(int u, int v)
{
  int lca = LCA(u,v);
  int ans = query_up(u,lca);
  int temp = query_up(v,lca);
  if(temp > ans) ans = temp;
  printf("%d\n",ans);
}

void change(int i,int val)
{
  int u = otherEnd[i];
  update_tree(1,1,ptr-1,posInBase[u],val);
}

void HLD(int curNode, int _cost, int prev)
{
  if(chainHead[chainNo] == -1)
    chainHead[chainNo] = curNode;
  chainInd[curNode] = chainNo;
  posInBase[curNode] = ptr;
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
      otherEnd[index[cur][i]] = adj[cur][i];
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
      index[i].clear();
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
      index[u].push_back(i);
      adj[v].push_back(u);
      cost[v].push_back(c);
      index[v].push_back(i);
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
      if(s[0]=='D') break;
      int a, b;
      scanf("%d%d",&a,&b);
      if(s[0]=='Q')
        query(a,b);
      else
        change(a,b);
    }
  }
}

