#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>

using namespace std;
vector<int> fib;

int main()
{
  map<int , int> hash;
  fib.push_back(0);
  fib.push_back(1);
  hash[0] = 1;
  hash[1] = 1;
  for(int i = 2; fib[i-1] < 1e9; i++)
  {
    fib.push_back(fib[i-1] + fib[i-2]);
    hash[fib[i]] = 1;
  }
  int n; 
  cin>> n;
  for(unsigned i=0; i< fib.size(); i++)
    for(unsigned j=i; j<fib.size(); j++)
    {
      if(hash.find(n-i-j) != hash.end())
      {
        printf("%d %d %d", fib[i],fib[j],n-i-j);
        return 0;
      }
    }
  puts("I'm too stupid to solve this problem");

  return 0;
}
