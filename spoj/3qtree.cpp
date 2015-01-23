#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
#define root 1
#define N 101000

vector<int> adj[N];
ll baseArray[N],ptr;
ll chainNo,chainInd[N],chainHead[N],posInBase[N];
ll depth[N],subSize[N],P[N];
ll st[N*6];

void make_tree(ll cur, ll p, ll q)
{
  if(q<p)return;
  if(p==q)
  {
    st[cur] = N+5;
    return;
  }
  ll mid = (p+q)/2;
  make_tree(2*cur,p,mid);
  make_tree(2*cur+1,mid+1,q);
  st[cur] = min(st[2*cur],st[2*cur+1]);
}

void update_tree(ll cur, ll p, ll q, ll x)
{
  if(q<p)return;
  if(p==q)
  {
    if(st[cur] == N+5)
      st[cur] = p;
    else
      st[cur] = N+5;
    return;
  }
  ll mid = (p+q)/2;
  if(x>mid)
    update_tree(2*cur+1,mid+1,q,x);
  else
    update_tree(2*cur,p,mid,x);

  st[cur] = min(st[2*cur],st[2*cur+1]);
}

ll query_tree(ll cur, ll p, ll q, ll l, ll r)
{
  if(p==l && q==r)
    return st[cur];
  ll mid = (p+q)/2;
  if(mid<l)
    return query_tree(2*cur+1,mid+1,q,l,r);
  else if(mid>=r)
    return query_tree(2*cur,p,mid,l,r);
  else
    return min(query_tree(2*cur,p,mid,l,mid),query_tree(2*cur+1,mid+1,q,mid+1,r));
}

ll query_up(ll u, ll v)
{
  ll uchain,ans = N+5;
  while(u!=v)
  {
    uchain = chainInd[u];
    ans = min(ans,query_tree(1,1,ptr-1,posInBase[chainHead[uchain]],posInBase[u]));
    u = chainHead[uchain];
    if(u!=v)
     u = P[u];
  }
  return ans;
}


void query(ll u, ll v)
{
  ll ans = query_up(u,v);
  if(ans == N+5) ans = -1;
  else ans = baseArray[ans];
  printf("%lld\n",ans);
}

void change(ll b)
{
  update_tree(1,1,ptr-1,posInBase[b]);
}

void HLD(ll curNode, ll prev)
{
  if(chainHead[chainNo] == -1)
    chainHead[chainNo] = curNode;
  chainInd[curNode] = chainNo;
  posInBase[curNode] = ptr;
  baseArray[ptr++] = curNode;
  ll sc = -1;
  for(unsigned i=0; i<adj[curNode].size(); i++)
  {
    if(adj[curNode][i] != prev)
      if(sc == -1 || subSize[sc] < subSize[adj[curNode][i]])
      {
        sc = adj[curNode][i];
      }
  }
  if(sc != -1)
    HLD(sc,curNode);

  for(unsigned i=0; i<adj[curNode].size(); i++)
    if(adj[curNode][i] != prev && sc != adj[curNode][i])
    {
      chainNo++;
      HLD(adj[curNode][i],curNode);
    }
}

void dfs(ll cur, ll prev, ll  _depth)
{
  P[cur] = prev;
  depth[cur] = _depth;
  subSize[cur] = 1;
  for(unsigned i=0; i<adj[cur].size(); i++)
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
  ptr = 1;
  ll n,q,a,b;
  scanf("%lld%lld",&n,&q);

  for(ll i=1; i<=n; i++)
    chainHead[i] = -1;
  for(ll i=1; i<n; i++)
  {
    scanf("%lld%lld",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a); 
  }

  chainNo = 1;
  dfs(root,-1,0);
  HLD(root,-1);
  make_tree(1,1,ptr-1);
  while(q--)
  {
    scanf("%lld%lld",&a,&b);
    if(a == 0)
      change(b);
    else
      query(b,1);
  }
}

