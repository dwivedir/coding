#include<iostream>
#include<stdio.h>

#define mod 1000000007
#define N 2005
using namespace std;

long long dp[N][N];
char str[100];
int main()
{
  FILE *fp1 = stdin;//fopen("/home/hp/Desktop/codes/fb/winning_at_sports.txt","r");
  FILE *fp2 = stdout;//f("/home/hp/Desktop/codes/fb/C_output.txt","w");

  int t,n1,n2;
  fscanf(fp1,"%d",&t);
  for(int k=1; k<=t; k++)
  {
    fscanf(fp1,"%s",str+1);
    n1 = 0; n2 = 0;
    int i=1;
    for(;str[i]!='-';i++)
    {
      n1 *= 10;
      n1 += str[i] - '0';
    }
    i++;
    for(;str[i];i++)
    {
      n2 *= 10;
      n2 += str[i] - '0';
    }
    dp[0][0] = 0;
    for(int i=1; i<=n1; i++)
      dp[i][0] = 1;
    long long ans = 0;
    for(int i=1; i<=n1; i++)
    {
      for(int j=1; j<i; j++)
      {
        dp[i][j] = 0;
        if(i-1>j)
          dp[i][j] += dp[i-1][j];
        if(j-1>=0)
          dp[i][j] += dp[i][j-1];
        dp[i][j] %= mod;
        if(i==n2){
          ans += dp[i][j];
          ans %= mod;
        }
      }
    }
    ans += dp[n2][0];
    if(!ans) ans = 1;
    fprintf(fp2,"Case #%d: %lld %lld\n",k,dp[n1][n2],ans);
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
