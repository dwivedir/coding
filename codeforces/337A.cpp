#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
  int array[100],n,m;
  scanf("%d%d", &n, &m);
  for(int i=1; i<= m; i++)
    cin >> array[i];

  sort(array+1,array+m+1);
  int min = 1e5;
  for(int i =1; i+n-1<=m; i++)
  {
    if(array[i+n-1] - array[i] < min)
      min = array[i+n-1] - array[i];
  }

  cout << min;

  return 0;

}
