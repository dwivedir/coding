#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
  int n,s;
  cin>>n>>s;
  if(n == 1 && s == 0)
  {
    puts("0 0");
    return 0;
  }
  if(s == 0 || s > 9 * n)
  {
    puts("-1 -1");
    return 0;
  }
  char max[n+5],min[n+5];

  int lastNonZero = -1;
  for(int i = 1; i<=n; i++)
  {
    if(s>=9)
    {
      max[i] = '9';
      min[n-i+1] = max[i];
      s -= 9;
    }
    else
    {
      if(lastNonZero == -1 && s == 0) lastNonZero = i-1;
      max[i] = s + '0';
      min[n-i+1] = max[i];
      s = 0;
    }
  }


  if(lastNonZero != -1){
    lastNonZero = n + 1 - lastNonZero;
    min[1] += 1;
    min[lastNonZero] -= 1;
  }

  min[n+1] = max[n+1] = '\0';

  cout<< (min+1)<<" "<<(max+1);

  return 0;
}
  
