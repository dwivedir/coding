#include<iostream>
#include<stdio.h>
#define mod 1000000007
using namespace std;

int main()
{
  int t,a,b,k;
  long long f[100005],sum[100005];
  cin>>t>>k;
  f[0] = 1;
  sum[0] = 0;
  for(int i=1; i<=1e5; i++)
  {
    f[i] = f[i-1];
    if(i-k>=0){
      f[i] +=  f[i-k];
      f[i] %= mod;
    }
    sum[i] = (f[i] + sum[i-1])%mod;
  }

  long long x;
  while(t--)
  {
    cin>>a>>b;
    x = sum[b]-sum[a-1];
    if(x>=0)
      cout<<x<<endl;
    else
    {
      x = x%mod + mod;
      cout<<x<<endl;
    }
  }

  return 0;
}
