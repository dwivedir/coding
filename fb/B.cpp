#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 1000005
using namespace std;

int Array[N][26];
char str[N];
int main()
{
  FILE *fp1 = stdin;//fopen("/home/hp/Desktop/codes/fb/autocomplete.txt","r");
  FILE *fp2 = stdout;//fopen("/home/hp/Desktop/codes/fb/B_output.txt","w");
  int n,t;
  fscanf(fp1,"%d",&t);
  for(int k=1; k<=t; k++)
  {
    for(int i=0; i<26; i++)
      Array[1][i] = 0;
    int ans = 0,ptr = 2;
    fscanf(fp1,"%d",&n);
    for(int i=1; i<=n; i++)
    {
      fscanf(fp1,"%s",str+1);
      int cur = 1;
      bool answered = 0;
      for(int j=1; str[j]; j++)
      {
        if(Array[cur][str[j]-'a'] != 0)
          cur = Array[cur][str[j]-'a'];
        else
        {
          if(!answered){
            ans += j;
            answered = 1;
          }
          Array[cur][str[j]-'a'] = ptr;
          for(int i=0; i<26; i++)
            Array[ptr][i] = 0;
          ptr++;
          cur = Array[cur][str[j]-'a'];
        }
      }
      if(!answered)
        ans += strlen(str+1);
      //cout<<ans<<endl;
    }
    fprintf(fp2,"Case #%d: %d\n",k,ans);
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
