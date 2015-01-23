#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  long long t,n,sum,x,k;
  cin>>t;
  while(t--)
  {
    cin>>n;
    sum = k = 0;
    for(int i=1;i<=n; i++)
    {
      cin>>x;
      if(x != 0) k++;
      sum += x;
    }
    if(sum-k < 100 && 100<=sum)
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
    
