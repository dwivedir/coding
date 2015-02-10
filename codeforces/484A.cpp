#include<iostream>
#include<stdio.h>

using namespace std;
long long length(long long R)
{
  long long y = 1;
  while(y<=R)
  {
    y <<= 1;
  }
  if(y==R)
    return y;
  else
    return y/2;
}

long long ans(long long l, long long r)
{
  if(l==r)
    return l;
  long long b = length(r);
  if(b*2-1 == r)
    return r;
  if(b>l)
    return b-1;
  else
    return b + ans(l-b,r-b);
}

int main()
{
  long long l,r;
  int n;
  cin>>n;
  while(n--)
  {
    cin>>l>>r;
    cout<<ans(l,r)<<endl;
  }
  return 0;
}
