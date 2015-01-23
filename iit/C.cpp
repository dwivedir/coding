#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll power(ll x, ll n)
{
  ll y = 1;
  while(n>0)
  {
    if(n&1) y = (y*x)%mod;
    x = (x*x)%mod;
    n >>=1;
  }
  return y;
}

int main()
{
  int t;
  ll n,m;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    ll ans = m;
    if(n>1)
      ans = (ans * (m-1))%mod;
    ans = (ans * power(m-2,n-2))%mod;
    cout<<ans<<endl;
  }

  return 0;
}
