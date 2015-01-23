#include<iostream>
#include<string.h>
#include<map>

using namespace std;
int main()
{
  map<int,int> hash;
  int n,m,array[100005];
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>array[i];
  for(int i=n; i>0; i--)
  {
    if(hash.find(array[i]) == hash.end())
      hash[array[i]] = 1;

    array[i] = hash.size();
  }
  while(m--)
  {
    cin>>n;
    cout<<array[n]<<endl;
  }

  return 0;
}
