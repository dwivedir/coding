#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n, array[100005],inc[100005], forward[100005];
  array[0] = forward[0] = 0;
  cin>>n;
  for(int i=1; i<=n; i++)
  { 
    cin>>array[i];
    if(array[i] > array[i-1])
      forward[i] = forward[i-1];
    else
      forward[i] = 1;
  }
  int l =1;
  inc[n] = 1;
  for(int i=n-1; i>0; i--)
  {
    if(array[i+1] > array[i])
      l++;
    else
      l = 1;
    inc[i] = l;
  }

  int max = -1;
  for(int i=1; i<=n; i++)
  {
    
  }


  cout<< max;
  return 0;
}
