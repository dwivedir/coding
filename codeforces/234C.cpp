#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n, array[100005],pos[100005],neg[100005];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>array[i];
  int ans= 0;
  if(array[1] >= 0) ans++;
  if(array[n] <= 0) ans++;
  pos[1] = 0;
  for(int i=2; i<=n-1; i++)
    if(array[i] >= 0)
      pos[i] = pos[i-1] + 1;
    else
      pos[i] = pos[i-1];
  neg[n] = 0;
  for(int i=n-1; i>1; i--)
    if(array[i] <= 0)
      neg[i] = neg[i+1] + 1;
    else
      neg[i] = neg[i+1];

  int val = 1e6;
  for(int i=1; i<=n-1; i++)
  {
    val = min(val, pos[i]+neg[i+1]);
  }

  cout<<ans+val;

  return 0;
}
