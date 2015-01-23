#include<iostream>
#include<stdio.h>
#include<vector>
#define N 10000005
using namespace std;
int dp[N][11];
int count[N];
bool isPrime[N];
int main()
{
  for(long long i=2; i<=1e7; i++)
  {
    if(!isPrime[i])
    {
      for(long long j=i; j<=1e7; j+=i){
        isPrime[j] = 1;
        count[j]++;
      }
    }
  }
  for(int i=2; i<=1e7; i++)
  {
    for(int j = 1; j<11; j++)
      dp[i][j] = dp[i-1][j];
    dp[i][count[i]] ++;
  }
  //FILE *fp1 = fopen("/home/hp/Desktop/codes/fb/homework.txt","r");
  //FILE *fp2 = fopen("/home/hp/Desktop/codes/fb/A_output.txt","w");

  int t,a,b,c,k,ans;
  fscanf(stdin,"%d",&t);
  for(int k=1; k<=t; k++)
  {
    fscanf(stdin,"%d%d%d",&a,&b,&c);
    if(c>10)
      ans = 0;
    else
      ans = dp[b][c] - dp[a-1][c];
    fprintf(stdout,"Case #%d: %d\n",k,ans);
  }
  //fclose(fp1);
  //fclose(fp2);
  return 0;
}
