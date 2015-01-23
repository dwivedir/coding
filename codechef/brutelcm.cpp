#include<iostream>
#include<stdio.h>

using namespace std;

long long gcd(long long a, long long b)
{
  if(a == 0)
    return b;
  else
    return gcd(b%a,a);
}
long long permute(int i, int n,int m,int k,int l)
{
  if(i>n)
  {
    if(l % k == 0){
      return 1;
    }
    return 0;
  }
  long long ans = 0;
  for(int j=1; j<=m; j++)
    ans += permute(i+1,n,m,k,l*j/gcd(l,j));

  return ans;
}
int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  cout<<permute(1,n,m,k,1);
  return 0;
}
