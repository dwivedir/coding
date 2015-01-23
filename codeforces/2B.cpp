#include<iostream>
#include<stdio.h>

using namespace std;

struct node
{
  int two;
  int five;
  char dir;
}map[1005][1005];
int power(int x,int base)
{
  int y = 0;
  while(x % base == 0)
  {
    y++;
    x/=base;
  }
  return y;
}

void print(int x,int y)
{
  if(map[x][y].dir == '\0')
    return;
  else if(map[x][y].dir == 'R')
    print(x,y-1);
  else
    print(x-1,y);
  cout<<map[x][y].dir;
}
int main()
{
  int n;
  int mat[1005][1005];
  cin>>n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      cin>>mat[i][j];

  map[1][1].two = power(mat[1][1],2);
  map[1][1].five = power(mat[1][1],5);
  map[1][1].dir = '\0';
  
  for(int i=2; i<=n; i++)
  {
    map[1][i].two = map[1][i-1].two + power(mat[1][i],2);
    map[1][i].five = map[1][i-1].five + power(mat[1][i],5);
    map[1][i].dir = 'R';

    map[i][1].two = map[i-1][1].two + power(mat[i][1],2);
    map[i][1].five = map[i-1][1].five + power(mat[i][1],5);
    map[i][1].dir = 'D';
  }

  for(int i=2; i<=n; i++)
    for(int j=2; j<=n; j++)
    {
      int left2 = map[i][j-1].two;
      int left5 = map[i][j-1].five;
      int up2 = map[i-1][j].two;
      int up5 = map[i-1][j].five;
      int minLeft = min(left2,left5);
      int minUp = min(up2,up5);

    }

  cout<<min(map[n][n].two,map[n][n].five)<<endl;

  print(n,n);

  return 0;
}
