#include<iostream>

using namespace std;
int main()
{
  int n, array[100005],left[100005],right[100005];
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>array[i];

  if(n<3)
  {
    cout << n;
    return 0;
  }
  left[n] = 1;
  for(int i= n-1; i>0; i--)
  {
    if(array[i] < array[i+1])
      left[i] = left[i+1] +1;
    else
      left[i] = 1;
  }
   
  right[1] = 1;
  for(int i=2; i<=n; i++)
  {
    if(array[i] > array[i-1])
      right[i] = right[i-1] + 1;
    else
      right[i] = 1;
  }
  int ans = max(1+left[2],1+right[n-1]);
  for(int i=2; i<n; i++)
  {
    //cout<<"left="<<left[i] <<" right ="<<right[i]<<endl;
    if(array[i-1]+2 <= array[i+1])
      ans = max(ans, 1+ left[i+1]+right[i-1]);
    else
      ans = max(ans,max( 1+left[i+1], 1+ right[i-1]));
  }
  cout<<ans;
  return 0;
}
