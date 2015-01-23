#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
  long long t,n,k,x,absent[100005];
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld",&n,&k);
    long long sumList,sumK = 0;
    bool answered = 0;
    for(int i= 1; i<=k; i++)
      scanf("%lld",&absent[i]);
    sort(absent+1,absent+1+k);
    for(int i=1; i<=k; i++)
    {
      sumList = (absent[i]-1)*absent[i]/2 - sumK;
      sumK += absent[i];
      if(absent[i]>sumList){
        if(absent[i]&1)
          puts("Chef");
        else
          puts("Mom");
        answered = 1;
        break;
      }
    }
    if(!answered)
    {
      sumList = n*(n+1)/2 - sumK;
      sumList++;
      if(sumList&1)
        puts("Chef");
      else
        puts("Mom");
    }
  }
  return 0;
}
