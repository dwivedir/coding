#include<iostream>
#include<algorithm>

using namespace std;

struct order
{
  int number;
  int tip;
};
bool cmp(order a, order b)
{
  if(a.tip>=b.tip)
    return 1;
  return 0;
}
int main()
{
  int n,x,y;
  int alice[100005],bob[100005];
  order diff[100005];
  cin>>n>>x>>y;
  for(int i=1; i<=n; i++)
  {
    cin>>alice[i];
  }
  for(int i=1; i<=n; i++)
  { 
    cin>> bob[i];
    diff[i].tip = alice[i]-bob[i];
    diff[i].number = i;
  }

  sort(diff+1,diff+1+n,cmp);
  int sum = 0,i =1, j = n;
  for(i=1; x>0 && diff[i].tip>=0; i++,x--)
  {
    sum += alice[diff[i].number];
  }

  for(j=n; y>0 && diff[j].tip <0; j--,y--)
    sum += bob[diff[j].number];

  for(int k=i;k<=j;k++)
  {
    if(diff[k].tip >= 0)
    {
      if(x >0)
      {
        sum += alice[diff[k].number];
        x--;
      }
      else
      {
        sum += bob[diff[k].number];
        y--;
      }
    }
    else
    {
      if(y > 0)
      {
        sum += bob[diff[k].number];
        y--;
      }
      else
      {
        sum += alice[diff[k].number];
        x--;
      }
    }
  }


  cout<<sum;

  return 0;
}

