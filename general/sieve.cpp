#include<bits/stdc++.h>
using namespace std;
bool notprime[100005];
int main()
{
  notprime[1] = notprime[0] = true;
  for(long long i = 2; i<=1e5; i++)
  {
    if(!notprime[i])
    {
      for(long long j=i*i; j<=1e5; j+=i)
        notprime[j] = true;
    }
  }
}
