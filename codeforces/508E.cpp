#include<iostream>
#include<stdio.h>
#define N 605
using namespace std;

bool Z[N][N] ;
int s[N][N];
int L[N],R[N];

bool inRange(int x, int i)
{
  return x>=L[i] && x<=R[i];
}

void print(int i, int j)
{
  if(i>j) return;
  if(s[i][j] == -1)
  {
    printf("(");
    print(i+1,j);
    printf(")");
  }
  else
  {
    print(i,s[i][j]);
    print(s[i][j] +1, j);
  }
}
int main()
{
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>L[i]>>R[i];
  for(int i=1; i<=n; i++)
    if(inRange(1,i)){
        Z[i][i] = true;
        s[i][i] = -1;
    }
  for(int l=2; l<=n; l++)
  {
    for(int i=1; i<=n-l+1; i++)
    {
      int j = i+l-1;
      int d = 2*l-1;
      for(int k=i; k<j; k++){
        Z[i][j] |= Z[i][k] && Z[k+1][j];
        if(Z[i][j] && !s[i][j])
          s[i][j] = k;
      }
      if(!Z[i][j] && inRange(d,i)){
        Z[i][j] |= Z[i+1][j];
        if(Z[i][j])
          s[i][j] = -1;
      }
    }
  }

  /*for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
      cout<<Z[i][j]<<" ";
    cout<<endl;
  }
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
      cout<<s[i][j]<<" ";
    cout<<endl;
  }*/
  if(!Z[1][n])
    cout<<"IMPOSSIBLE";
  else
    print(1,n);
  return 0;
}


