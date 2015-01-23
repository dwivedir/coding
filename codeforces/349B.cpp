#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
  int cost[10],minc = 1e6, minv,v;
  cin>>v;
  for(int i=1; i<=9;i++){
    cin>>cost[i];
    if(cost[i] <= minc)
    {
      minc = cost[i];
      minv = i;
    }
  }

  if(minc > v)
  {
    puts("-1");
    return 0;
  }
  int l = v/minc,x=v%minc;
  char str[l+5];
  for(int i=1; i<=l; i++){
    str[i] = minv + '0';
    for(int j=9;x>0&&j>minv;j--){
      if(cost[j] - minc <= x)
      {
        str[i] = j +'0';
        x = x + minc - cost[j];
        break;
      }
    }
  }
  str[l+1] = '\0';
  puts(str+1);

  return 0;

}
