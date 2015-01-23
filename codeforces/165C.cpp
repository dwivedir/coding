#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
char str[1000005];
int cnt[1000005];
int main()
{
  int k;
  long long ans=0;
  cin>>k>>(str+1);

  int sum = 0;
  
  for(int i=1; str[i]; i++)
  {
    sum += str[i] - '0';
    cnt[sum]++;
    if(k>0){
      if(sum >= k)
        ans += cnt[sum - k];
    }
    else
      ans += cnt[sum] -1;
    if(sum==k)
      ans++;
  }
  
  cout<<ans;

  return 0;
}
