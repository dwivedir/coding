#include<iostream>
#include<stdio.h>
typedef long long ll;
using namespace std;

ll pos(ll x)
{
  if(x<0)
    return -x; 
  return x;
}
int main()
{
  int t;
  ll e,o;
  cin>>t;
  while(t--)
  {
    cin>>e>>o;
    ll x = (e+o)/5;
    if((e+o)%5 != 0)
      puts("-1");
    else
      cout<<pos(e-x*2)<<endl;
  }

  return 0;
}
