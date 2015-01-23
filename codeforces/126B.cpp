#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char pattern[1000005];
int p[1000005];
void preprocessing(char pattern[])
{
  int size = strlen(pattern+1);
  p[1] = 0;
  int k = 0;
  for(int i=2; i<=size; i++)
  {
    while(k > 0 && pattern[i] != pattern[k+1])
    {
      k = p[k];
    }

    if(pattern[i] == pattern[k+1])
      k++;
    p[i] = k;
  }

}

void print(int i)
{
  pattern[i+1] = '\0';
  cout<<(pattern+1);
}
int main()
{
  cin>>(pattern+1);
  preprocessing(pattern);
  int l = strlen(pattern+1);
  if(p[l] == 0)
    puts("Just a legend");
  else
  {
    int ans = -1;
    for(int i=1; i<l; i++)
      if(p[i] == p[l]){
        ans = p[i];
        print(ans);
        return 0;
      }
    ans = p[p[l]];
    if(ans == 0)
      puts("Just a legend");
    else
      print(ans);
  }
  return 0;
}

