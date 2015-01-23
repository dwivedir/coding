#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int mod(int x, int d)
{
  x %= d;
  if(x<0) x += d;
  return x;
}

int absolute(int x)
{
  if(x<0) x = -x;
  return x;
}

int main()
{
  int n,m,d,neg = 0,array[10005];
  cin>>n>>m>>d;
  cin>>array[1];
  for(int i=2; i<=n*m; i++)
  {
    cin>>array[i];
    if(mod(array[i]-array[1],d) != 0)
      neg = 1;
  }

  if(neg)
  {
    puts("-1");
    return 0;
  }

  sort(array+1,array+1+n*m);
  int median = array[(n*m+1)/2];
  long long sum = 0;
  for(int i=1; i<=n*m; i++)
  {
    sum += absolute(array[i]-median)/d;
  }

  cout<<sum;
  return 0;
}


