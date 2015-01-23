#include<iostream>
#include<stdio.h>

using namespace std;

struct node
{
  int rem[3];
  int sum;
};

node tree[300000];
struct node merge(node a, node b)
{
  struct node res;
  res.sum = (a.sum+b.sum)%3;
  for(int i=0; i<3; i++)
  {
    res.rem[i] = a.rem[i];
  }
  for(int i=0; i<3; i++)
    res.rem[(i+a.sum)%3] += b.rem[i];

  return res;
}

void build(int index, int p, int q, char array[])
{
  if(q<p) return;
  if(p==q)
  {
    tree[index].sum = (array[p] - '0')%3;
    for(int i=1; i<3; i++)
      tree[index].rem[i] = 0;
    tree[index].rem[tree[index].sum]++;
    return;
  }
  int mid = (p+q)/2;
  build(2*index,p,mid,array);
  build(2*index+1,mid+1,q,array);
  tree[index] = merge(tree[2*index],tree[2*index+1]);
}

void update(int index, int p, int q, int newIndex, int newVal)
{
  if(q<p)
    return;
  if(p==q)
  {
    tree[index].sum = (newVal)%3;
    for(int i=0; i<3; i++)
      tree[index].rem[i] = 0;
    tree[index].rem[tree[index].sum]++;
    return;
  }
  int mid = (p+q)/2;
  if(mid<newIndex)
    update(2*index+1,mid+1,q,newIndex,newVal);
  else
    update(2*index,p,mid,newIndex,newVal);

  tree[index] = merge(tree[2*index],tree[2*index+1]);
}

struct node query(int index, int p, int q, int l, int r)
{
  if(p == l && q == r)
    return tree[index];
  int mid=(p+q)/2;
  if(mid<l)
    return query(2*index+1,mid+1,q,l,r);
  else if(mid>=r)
    return query(2*index,p,mid,l,r);
  else
    return merge(query(2*index,p,mid,l,mid),query(2*index+1,mid+1,q,mid+1,r));
}

long long Divisible(node a)
{
  long long res = 0;
  for(int i=0; i<3; i++)
  {
    long long val = a.rem[i];
    if(i==0)
      val++;
    res += val*(val-1)/2;
  }
  return res;
}

int main()
{
  int n,m;
  char array[100005];
  cin>>n>>m>>(array+1);
  build(1,1,n,array);
  while(m--)
  {
    int type,x,y;
    cin>>type>>x>>y;
    if(type == 1)
      update(1,1,n,x,y);
    else
      cout<<Divisible(query(1,1,n,x,y))<<endl;
  }
  return 0;
}
