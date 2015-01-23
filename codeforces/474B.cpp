#include<iostream>
#include<stdio.h>

using namespace std;

int binary(int array[], int p, int q, int x)
{
  if(q<p) return -1;
  if(p == q)
  {
    if(array[p] >= x) return p;
    else return -1;
  }
  int mid = (p+q)/2;
  if(array[mid]== x)
    return mid;
  else if(array[mid] > x)
    return binary(array, p, mid, x);
  else
    return binary(array, mid+1, q, x);
}
int main()
{
  int n,m,array[100005],x;
  cin >> n;
  array[0] = 0;
  for(int i=1; i<=n; i++)
  {
    cin>> array[i];
    array[i] += array[i-1];
  }
  cin>> m;
  for(int i=1; i<=m; i++)
  {
    cin >> x;
    cout << binary(array, 1, n, x) << endl;
  }

  return 0;
}
