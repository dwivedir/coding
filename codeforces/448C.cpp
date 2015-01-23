#include<iostream>
#include<stdio.h>
#define N 5100
using namespace std;
int st[N*6];

int merge(int a, int b, int array[])
{
  if(array[a]<=array[b])
    return a;
  else
    return b;
}
void make_tree(int index, int p, int q, int array[])
{
  if(q<p)return ;
  if(p==q)
  {
    st[index] = p;
    return;
  }
  int mid = (p+q)/2;
  make_tree(2*index,p,mid,array);
  make_tree(2*index+1,mid+1,q,array);
  st[index] = merge(st[2*index+1],st[2*index],array);
}

int query(int index, int p, int q, int l, int r,int array[])
{
  if(p==l && q==r)
    return st[index];
  int mid = (p+q)/2;
  if(mid<l)
    return query(2*index+1,mid+1,q,l,r,array);
  else if(mid>=r)
    return query(2*index,p,mid,l,r,array);
  else
    return merge(query(2*index,p,mid,l,mid,array),query(2*index+1,mid+1,q,mid+1,r,array),array);
}

int fun(int l, int r, int done, int array[], int n)
{
  if(r<l) return 0;
  else if(l==r&& array[l]>done)
    return 1;
  else if(l==r)
    return 0;
  int low = query(1,1,n,l,r,array);
  int x = fun(l,low-1,array[low],array,n);
  int y = fun(low+1,r,array[low],array,n);
  int ans = r-l+1;
  ans = min(ans, x+y+array[low]-done);
  return ans;
}

int main()
{
  int n;
  int array[N];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>array[i];
  make_tree(1,1,n,array);
  cout<<fun(1,n,0,array,n);
  return 0;
}
