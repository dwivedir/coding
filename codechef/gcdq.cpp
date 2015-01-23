#include<iostream>
#include<stdio.h>

using namespace std;

int gcd(int a, int b)
{
  if(a == 0)
    return b;
  else
    return gcd(b%a, a);
}
int main()
{
  int t,n,q,A[100005];
  int gcdLeft[100005],gcdRight[100005];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&q);
    gcdLeft[0] = 0;
    for(int i=1; i<=n; i++)
    {
      scanf("%d",&A[i]);
      gcdLeft[i] = gcd(gcdLeft[i-1],A[i]);
    }
    gcdRight[n+1] = 0;
    for(int i=n; i>0; i--)
      gcdRight[i] = gcd(gcdRight[i+1],A[i]);

    while(q--)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      printf("%d\n",gcd(gcdLeft[l-1],gcdRight[r+1]));
    }
  }

  return 0;
}
