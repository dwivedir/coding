#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
vector<int> seq;
int binary(int p,int q, int x)
{
  if(q<p) return -1;
  if(p==q)
  {
    if(seq[p] >= x) return p;
    return -1;
  }

  int mid = (p+q)/2;
  if(seq[mid]>=x)
    return binary(p,mid,x);
  else
    return binary(mid+1,q,x);
}

int  main()
{
  int n,array[100005];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>array[i];
  for(int i=1; i<=n; i++)
  {
    if(seq.empty() || seq[seq.size()-1] < array[i])
      seq.push_back(array[i]);
    else
    {
      int position = binary(0,seq.size()-1,array[i]);
      seq[position] = array[i];
    }
  }
  cout<<seq.size();
  return 0;
}
