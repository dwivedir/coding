#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int x,row,col;
  for(int i =1; i<=5; i++)
    for(int j=1; j<=5; j++)
    {
      cin >> x;
      if(x)
      {
        row = i;
        col = j;
      }
    }
  row = row-3;
  col = col -3;
  if(row<0)row = -row;
  if(col<0)col = -col;

  cout << (row+col);

  return 0;
}
