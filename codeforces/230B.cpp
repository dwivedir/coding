#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int prime[1000001];
int main()
{
  prime[1] = 1;
  for(long long i =2; i<=1e6; i++)
  {
    if(!prime[i])
    {
      for(long long j = i*i; j<=1e6; j += i)
        prime[j] =1;
    }
  }

  int n;
  long long x,p;
  cin>>n;
  while(n--)
  {
    cin>> x;
    long long y = sqrt(x);
    p = y;
    y *= y;
    if(y == x && !prime[p])
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
