#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int n,t,position=1;
  int array[30005];

  cin>>n>>t;
  for(int i=1; i<n; i++)
    cin>>array[i];

  while(position<t)
  {
    position += array[position];
  }

  if(position == t)
    puts("YES");
  else
    puts("NO");

  return 0;

}
