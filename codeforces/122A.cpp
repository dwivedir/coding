#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
  int lucky[100] = { 0, 4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 477, 747, 774, 777 };
  int x,ans=1;
  cin >> x;
  for(int i=1; i<= 14; i++)
  {
    if(x % lucky[i] == 0)
    {
      printf("YES");
      ans=0;
      break;
    }
  }
  if(ans)
    printf("NO");

  return 0;

}
  
