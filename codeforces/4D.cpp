#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
struct node
{
  long long length;
  long long breadth;
  int location;
};
vector<node> list;

bool comp(node a, node b)
{
  if(a.length*a.breadth > b.length*b.breadth)
    return 0;
  return 1;
}

void print(int x,int pre[])
{
  if(x == -1) return ;
  print(pre[x],pre);
  cout<<list[x].location<<" ";
}

int main()
{
  int n,l,b;
  cin>>n>>l>>b;
  node point;
  for(int i=1; i<=n; i++)
  {
    cin>>point.length>>point.breadth;
    point.location = i;
    if(point.length>l && point.breadth > b)
      list.push_back(point);
  }

  sort(list.begin(),list.end(),comp);

  int dp[5005],pre[5005];
  for(unsigned i=0; i<list.size(); i++)
  {
    //cout<<list[i].length<<" "<<list[i].breadth<<endl;
    int val = 0,pos = -1;
    for(int j=0; j<i; j++)
    {
      if(list[i].length>list[j].length && list[i].breadth > list[j].breadth && dp[j] > val)
      {
        val = dp[j];
        pos = j;
      }
    }
    dp[i] = val + 1;
    pre[i] = pos;
  }

  int val = 0;
  int pos = -1;
  for(unsigned i=0; i<list.size(); i++)
  {
   if(dp[i] > val)
   {
    val = dp[i];
    pos = i;
   }
  }
  
  cout<<val<<endl;
  print(pos,pre);
  return 0;
} 
