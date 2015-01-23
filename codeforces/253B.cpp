#include<iostream>
#include<algorithm>
using namespace std;

int binary(int array[], int p,int q, int x)
{
  if(q<p) return -1;
  else if(q==p)
  {
    if(array[p] <= x) return p;
    return -1;
  }
  else if(q == p+1)
  {
    if(array[q] <=x) return q;
    else if(array[p] <= x) return p;
    return -1;
  }

  int mid = (p+q)/2;
  if(array[mid] <= x) return binary(array,mid,q,x);
  else return binary(array,p,mid-1,x);
}
int main()
{
  int n, array[100005];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>> array[i];

  sort(array+1, array+1+n);
  int ans = n+1;
  for(int i=1; i<=n; i++)
  {
    int val = binary(array,1,n,2*array[i]);
    //cout<< val <<" "<<n-val+i-1<< endl;
    if(val==-1)
      ans = min(ans,i-1);
    else
      ans = min(ans,n-val+i-1);
  }

  cout<<ans;

  return 0;

}
