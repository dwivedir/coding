#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long fact(int n)
{
  if(n<=1) return 1;
  return n*fact(n-1);
}
int A[55];
long long Sum(int n)
{
  long long ans = 0;
  for(int i=1; i<=n;i++)
    for(int j=i; j<=n; j++)
    {
      long long val = 1e9;
      for(int k=i; k<=j; k++)
        val = min(val,(long long)A[k]);
      ans += val;
    }
  return ans;
}


int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    A[i] = i;
    cout<<i<<" ";
  }
  cout<<Sum(n)<<endl;
  int count = fact(n);
  for(int k=1; k<count; k++)
  {
    next_permutation(A+1,A+n+1);
    for(int j=1; j<=n; j++)
      cout<<A[j]<<" ";
    cout<<Sum(n)<<endl;
  }
  return 0;
}


