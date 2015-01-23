#include<iostream>
#include<stdio.h>

using namespace std;
int frd(int num, int k)
{
  int y =0;
  while(num>0)
  {
    if(num&1)y++;
    num >>=1;
  }
  if(y<=k)return 1;
  return 0;
}

int main()
{
  int n,m,k,x;
  int dif[1005],count=0;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1; i<=m ; i++)
    cin>> dif[i];
  cin>> x;
  for(int i=1; i<=m; i++)
  {
    if(frd(dif[i]^x,k))count++;
  }

  cout<< count;
  return 0;

}
