#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
  char str[2005];
  bool dp[2005][2005];
  int l;
  gets(str+1);
  l = strlen(str+1);
  //cout<<"l="<< l<<endl;
  for(int i=1; i<=l; i++)
  {
    dp[i][i] = 1;
    if(i!=l)
    {
      if (str[i] == str[i+1])
        dp[i][i+1] = 1;
      else
        dp[i][i+1] = 0;
    }
  }

  /*for(int i=1; i<=l; i++){
    for(int j=1; j<=l; j++){
      cout<<dp[i][j] << " ";
    }
    cout<<endl;
  }*/

  for(int k=3; k<=l; k++)
  {
    for(int i=1; i<= l-k+1; i++)
    {
      int j = i+k-1;
      if(str[i] == str[j] && dp[i+1][j-1])
        dp[i][j] = 1;
      else
        dp[i][j] = 0;
    }
  }

  long long sum[2005],ans=0;
  sum[1] = 1;sum[0] = 0;
  for(int i=2; i<=l; i++)
  {
    sum[i] = sum[i-1];
    for(int j=1; j<=i; j++)
    {
      sum[i] += dp[j][i];
      ans += dp[j][i]*sum[j-1];
    }
  }

  cout<<ans;

  return 0;

}

