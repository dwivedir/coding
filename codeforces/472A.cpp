#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  int x;
  cin >> x;
  if(x&1)
    printf("9 %d",x-9);
  else
    printf("4 %d",x-4);

  return 0;
}
