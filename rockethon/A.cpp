#include<iostream>
#include<stdio.h>

using namespace std;

int dp1[55][55],dp2[55][55];

int main()
{
  int n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;
  for(int i=0; i<= n2; i++){
    dp1[0][i] = 0;
    dp2[0][i] = 1;
  }
  for(int i=1; i<=n1; i++){
    dp1[i][0] = 1;
    dp2[i][0] = 0;
  }

  for(int i=1; i<=n1; i++)
  {
    for(int j=1; j<=n2; j++)
    {
      int x = 0,y = 0;
      for(int k=1; k<=k1 && k<=i; k++)
        if(dp2[i-k][j] == 0)
        {
          x = 1;
          break;
        }
      for(int k=1; k<=k2 && k<=j; k++)
        if(dp1[i][j-k] == 0)
        {
          y=1;
          break;
        }
      dp1[i][j] = x;
      dp2[i][j] = y;
    }
  }

  if(dp1[n1][n2])
    puts("First");
  else
    puts("Second");

  return 0;
}
