#include<iostream>
#include<stdio.h>
typedef long long ll;
using namespace std;

int main()
{
  int t;
  ll n,k;
  cin>>t;
  while(t--)
  {
    ll ans = 0;
    cin>>n>>k;
    if(k==1)
      cout<<n<<endl;
    else
    {
      while(n>0)
      {
        ans += n%k;
        n /= k;
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}

