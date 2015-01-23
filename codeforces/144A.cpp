#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n,x, minv = 105, maxv = 0, min, max;
  cin >> n;
  for(int i =1; i<= n; i++)
  {
    cin >> x;
    if(x<=minv)
    {
      minv = x;
      min = i;
    }
    if(x>maxv)
    {
      maxv = x;
      max = i;
    }
  }

  int neg = 0;
  if(min<max) neg = 1;
  --max;
  min = n -min;
  cout << (max + min -neg);

  return 0;
}

