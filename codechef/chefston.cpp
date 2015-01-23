#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n,t;
  long long k,A[100005],B[100005],ans;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    ans = -1;
    for(int i=1; i<=n; i++)
      cin>>A[i];
    for(int i=1; i<=n; i++)
      cin>>B[i];
    for(int i=1; i<=n; i++)
      ans = max(ans, (k/A[i])*B[i]);

    cout<<ans<<endl;
  }

  return 0;
}
