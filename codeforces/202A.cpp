#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

bool palindrome(char str[], int n)
{
  for(int i=0,j=n-1; i<j; i++,j--)
    if(str[i] != str[j])
      return false;
  return true;
}

int main()
{
  char str[15];
  char ans1[15] = {'\0'},ans2[15];
  cin>>str;
  int n,l = strlen(str);
  n = 1<<l;
  for(int i=0; i<n; i++)
  {
    int newL = 0;
    for(int j=0;j<l; j++)
    {
      if((1<<j)&i)
      {
        ans2[newL] = str[j];
        newL++;
      }
    }
    ans2[newL] = '\0';
    //cout<<ans2<<endl;
    if(palindrome(ans2,newL) && strcmp(ans2,ans1) == 1)
      strcpy(ans1,ans2);
    //cout<<ans2<<" "<<ans1<<endl;
  }

  cout<<ans1;
  return 0;
}
