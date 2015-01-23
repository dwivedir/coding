#include<iostream>
#include<stdio.h>
#include<stack>
#include<map>
using namespace std;
stack<int>book,spare;
map<int,int> hash;
int main()
{
  int n,m,w[505],b[1005];
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>w[i];
  for(int i=1; i<=m; i++)
    cin>>b[i];

  for(int i=1; i<=m; i++)
  {
    if(hash.find(b[i]) == hash.end())
    {
      hash[b[i]] = 1;
      spare.push(b[i]);
    }
  }

  while(!spare.empty())
  {
    book.push(spare.top());
    spare.pop();
  }

  int ans = 0;
  for(int i=1; i<=m; i++)
  {
    while(book.top() != b[i])
    {
      //cout<<book.top()<<endl;
      ans += w[book.top()];
      spare.push(book.top());
      book.pop();
    }
    book.pop();
    while(!spare.empty())
    {
      book.push(spare.top());
      spare.pop();
    }
    book.push(b[i]);
  }

  cout<<ans;
  return 0;
}
