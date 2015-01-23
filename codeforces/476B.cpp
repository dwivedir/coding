#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
int main()
{
  int fact[11];
  fact[0] = 1;
  for(int i=1; i<= 10; i++)
    fact[i] = fact[i-1] * i;

  char s1[15],s2[15];
  cin>>s1>>s2;
  int pos=0, neg=0, n=0;
  for(int i=0; s1[i]; i++)
  {
    if(s1[i] == '+') pos++;
    else neg++;
  }
  for(int i=0; s2[i]; i++)
  {
    if(s2[i] == '+') pos--;
    else if(s2[i] == '-') neg--;
    else n++;
  }
  if(pos<0){
    neg -= pos;
    pos = 0;
  }
  if(neg<0){
    pos -= neg;
    neg = 0;
  }
  if(pos+neg != n)
  {
    puts("0.000000000000");
    return 0;
  }
  
  printf("%0.12f", fact[n]/fact[pos]/fact[neg]/(double)(1<<n));

  return 0;

}
