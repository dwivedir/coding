#include<bits/stdc++.h>
using namespace std;

int done[1000000];
int main()
{
  int m,t,r,ans = 0;
  int add = 500;
  bool possible = true;
  cin>>m>>t>>r;
  for(int i=1; i<=m ;i++)
  {
    int w,L,R,x = 0;
    cin>>w;
    L = w-t;
    R = w-1;
    if(R-L+1<r)possible = false;
    for(int j = add+L; j<=add+R; j++)
    {
      if(done[j])
        x++;
    }
    for(int j = add+R; j >= add+L && x<r; j--){
      if(!done[j])
      {
        ans++;
        done[j] = 1;
        x++;
      }
    }
  }
  if(!possible)
    cout<<"-1";
  else
    cout<<ans;
  return 0;
}
