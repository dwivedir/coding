#include<iostream>

using namespace std;

int main()
{
  long long f[100005];
  long long int  cnt[100005],n,x;
  for(int i=1; i<=1e5; i++)
    cnt[i] = 0;
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>x;
    cnt[x]++;
  }
  f[0] = 0;
  f[1] = cnt[1];
  for(long long int i=2; i<= 1e5; i++)
  {
    long long p = cnt[i] * i;
    f[i] = max(f[i-1], f[i-2] + p);
  }

  cout<<f[100000];

  return 0;
}
