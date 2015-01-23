#include<iostream>
#include<stdio.h>
#define mod 1000000007
using namespace std;

long long power(long long x, long long n)
{
  long long y = 1;
  x %= mod;
  while(n>0)
  {
    if(n&1)
    {
      y = (y*x)%mod;
    }
    x = (x*x)%mod;
    n>>=1;
  }
  return y;
}

long long care(long long x)
{
  x %= mod;
  if(x>=0)
    return x;
  else
    return x+mod;
}
int main()
{
  int t,n,l,r,m;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d%d",&n,&m,&l,&r);
    long long superSum = power(m,n);
    long long sum = 0;
    for(int i=l; i<=r; i++)
    {
      sum += care(superSum - power(m-(m/i),n));
      sum %= mod;
    }
    cout<<sum<<endl;
  }
  return 0;
}
