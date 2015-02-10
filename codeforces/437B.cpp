#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
vector<int> list;

int p[100],q[100];
stack<int>choice[100];
int position(int x)
{
  int y=0;
  while(x>(1<<y))
    y++;
  return y;
}
int main()
{
  int sum,limit;
  cin>>sum>>limit;
  for(int i=0; (1<<i)<=sum; i++)
    if(sum & (1<<i)){
      p[i] = 1;
      //cout<<i<<" added"<<endl;
    }

  for(int i=1; i<=limit; i++)
  {
    int lo = position(i & ~(i-1));
    q[lo]++;
    choice[lo].push(i);
    //cout<<i<<" pushed in "<<lo<<endl;
  }
  int imp = 0;
  //for(int i=0; i<10; i++)
    //cout<<q[i]<<endl;
  for(int i=0; i<=20; i++)
  {
    if(p[i] > 0)
    {
      int r = 1;
      for(int j=i; j>=0; j--,r*=2)
      {
        int m = min(q[j],r);
        q[j] -= m;
        r -= m;
        //cout<<"i = "<<i<<" m = "<<m <<" r="<<r<<" q = "<<q[j] <<endl;
        while(m--)
        {
          list.push_back(choice[j].top());
          choice[j].pop();
        }
        
        if(r == 0)
          break;
      }
      if(r == 0)
        p[i] = 0;
    }
    if(p[i]){
      imp = 1;
      break;
    }
  }

  if(imp)
    puts("-1");
  else 
  {
    cout<<list.size()<<endl;
    for(int i=0; i<list.size();i++)
      cout<<list[i]<<" ";
  }
  return 0;
}
