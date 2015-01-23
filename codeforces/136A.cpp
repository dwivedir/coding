#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  int x[150],n,y;
  cin >> n;
  for(int i =1; i<=n;i++)
  {
    cin >> y;
    x[y] = i;
  }
  for(int i=1; i<=n; i++)
    printf("%d ", x[i]);

  return 0;
}
