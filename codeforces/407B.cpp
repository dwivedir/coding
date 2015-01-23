#include<iostream>
#include<stdio.h>
#define mod 1000000007
using namespace std;

int main()
{
  int n;
  long long sum[1005],penality[1005],even[1005],p[1005];
  cin>>n;
  for(int i=1; i<=n;i++)
    cin>>p[i];

  penality[1] = 1;
  sum[0] = 0;
  sum[1] = penality[1];
  for(int i=2; i<=n; i++)
  {
    penality[i] = (1 + i- p[i] + sum[i-1] - sum[p[i]-1])%mod;
    if(penality[i]<0) penality[i] += mod;
    sum[i] = (sum[i-1] + penality[i])%mod;
  }
  even[1] = 1;
  for(int i=2; i<=n; i++)
    even[i] = (even[i-1] + 1 + penality[i])%mod;

  cout<<(even[n] + 1)%mod;
  return 0;
}
