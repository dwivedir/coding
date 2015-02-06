#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n;i++)
  {
    if(i&1)
      for(int j=1; j<=m; j++)
        printf("#");
    else
    {
      int k = 1;
      if((i/2)&1)
        k = m;
      for(int j=1; j<=m; j++)
        if(j == k)
          printf("#");
        else
          printf(".");
    }
    cout<<endl;
  }
}


