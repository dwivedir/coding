#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int logLength(long long x)
{
  int length = 0;
  while(x>0)
  {
    length ++;
    x>>=1;
  }
  return length;
}
int main()
{
  long long x, y,a,b;
  cin>>x>>y;
  a = 0;
  b = 0;
  int length = logLength(y);
  //cout<<length<<endl;
  for(int i=length-1; i>=0; i--)
  {
    long long x1 = x >> i;
    long long y1 = y >> i;
    long long a1 = a<<1;
    long long b1 = b<<1;
    if((a1+1)>=x1 && (a1+1)<=y1 && b1>=x1 && b1<=y1)
    {
      a = a1+1; b = b1;
    }
    else if(a1>=x1 && a1<=y1 && (b1+1)>=x1 && (b1+1)<=y1)
    {
      a = a1;
      b = b1 + 1;
    }
    else
    {
      a = a1;
      b = b1;
      if((a<x1 || a >y1)||(b<x1 || b > y1))
      {
        a++;
        b++;
      }
    }
    //cout<<a<<" "<<b<<endl; 
  }
  cout<<(a^b);
  return 0;
}
