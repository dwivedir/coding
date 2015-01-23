#include<iostream>
#include<stdio.h>

using namespace std;
long long nc2(long long n)
{
  if(n<2)
    return 0;
  else
    return n*(n-1)/2;
}

int main()
{
  long long m,n,kmax=0,kmin=0,r,q;
  cin>>m >> n;
  q = m/n;
  r = m%n;
  kmin = r*nc2(q+1) + (n-r)*nc2(q);
  kmax = nc2(m-n+1);

  cout<< kmin << " " << kmax;
}
