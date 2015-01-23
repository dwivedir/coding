#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
  long long a;
  long long b;
};

bool comp(node first, node second)
{
  if(first.b > second.b)
    return 0;
  if(first.b == second.b && first.a > second.a)
    return 0;
  return 1;
}


int main()
{
  int t,n;
  struct node array[100005];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
      scanf("%lld%lld",&array[i].a,&array[i].b);
    }
    sort(array+1,array+1+n,comp);
    long long  ans = 0;
    long   last = -1;
    for(int i=1; i<=n; i++)
    {
      if(array[i].a > last)
      {
        last = array[i].b;
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
