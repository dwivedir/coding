#include<iostream>
#include<stdio.h>

#define mod 1000000007
using namespace std;
long long int y[3][3];
void multiply(int n)
{
  y[1][1] = y[2][2] = 1;
  y[1][2] = y[2][1] = 0;

  long long int x[3][3], temp[3][3];
  x[1][1] = 0;
  x[1][2] = 3;
  x[2][1] = 1;
  x[2][2] = 2;

  while(n>0)
  {
    if(n&1)
    {
      for(int i=1; i<=2; i++)
        for(int j=1;j<=2; j++)
        {
          temp[i][j] = 0;
          for(int k=1; k<=2; k++)
            temp[i][j] += (y[i][k] * x[k][j]) %mod;
        }
      for(int i=1; i<=2; i++)
        for(int j=1; j<=2; j++)
          y[i][j] = temp[i][j] % mod;
    }

    for(int i=1; i<=2; i++)
      for(int j=1;j<=2; j++)
      {
        temp[i][j] = 0;
          for(int k=1; k<=2; k++)
            temp[i][j] += (x[i][k] * x[k][j]) %mod;
        }
      for(int i=1; i<=2; i++)
        for(int j=1; j<=2; j++)
          x[i][j] = temp[i][j] % mod;
      n >>=1;
  }
     
}


int main()
{
  int n;
  cin>>n;
  if(n==1)
  {
    puts("0");
    return 0;
  }
  multiply(n-1);
  cout<<y[1][2];
  return 0;
}

