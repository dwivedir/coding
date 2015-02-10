#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool even(char str[])
{
  int c1 = 0,c2 = 0;
  for(int i=0; str[i]; i++)
    if(str[i] == '4')
      c1++;
    else
      c2++;
  return (c1==c2);
}

int main()
{
  char x = '4';
  char str[15];
  char ans1[15],ans2[15];
  cin>>str;
  int l = strlen(str);
  int initial = l;
  if(l&1)
    l++;
  int n = 1<<l;
  for(int i=0; i<l; i++)
    ans1[i] = '7';
  ans1[l] = '\0';
  int ans = 0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<l; j++)
    {
      if((1<<j) & i)
      {
        ans2[j] = '7';
      }
      else
        ans2[j] = '4';
    }
    ans2[l] = '\0';
    if(even(ans2) && (l>initial || (l == initial && strcmp(ans2,str)>=0)) && strcmp(ans2,ans1)<0){
      strcpy(ans1,ans2);
      //cout<<ans1<<endl;
      ans = 1;
    }
  }

  if(!ans)
  {
    cout<<"44";
    for(int i=1; i<=l; i++)
    {
      if(i<= l/2 - 1)
        cout<<"4";
      else
        cout<<"7";
    }
  }
  else
    cout<<ans1;

  return 0;
}
