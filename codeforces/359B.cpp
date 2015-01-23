#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  n *= 2;
  while(k--)
  {
    cout<<n-1<<" "<<n<<" ";
    n -= 2;
  }

  for(int i=1; i<=n; i+=2)
    cout<<i+1<<" "<<i<<" ";

  return 0;

}

