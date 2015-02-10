#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
  long long count;
  char first;
  char last;
}s[55];

void printString(int n, int count, char first, char last)
{
  int i=1;
  if(first == 'A'){
    cout<<'A';
    if(count){
      cout<<'C';
      count--;
      i+= 2;
    }
    else
      i++;
  }
  else
  {
    cout<<first;
    i++;
  }
  while(count--)
  {
    cout<<"AC";
    i+=2;
  }
  while(i<n){
    cout<<'K';
    i++;
  }
  if(i==n)
  cout<<last;
}

bool good(int n, int count, int first, int last)
{
  if(n==1)
    return (first == last && count == 0);
  if(n==2)
  {
    if(first == 'A' && last == 'C')
      return count == 1;
    else if(first !='A' || last!= 'C')
      return count == 0;
  }
  if(n&1)
  {
    if(2*count<n-1 || (2*count == n-1 && (first == 'A'|| last == 'C')))
      return true;
    else
      return false;
  }
  else
  {
    if(2*count<n || 2*count == n && first == 'A' && last == 'C')
      return true;
    else
      return false;
  }
}
void cal(int k, int x,int n, int m)
{
  for(int i=3;i<=k; i++)
  {
   s[i].count = s[i-2].count + s[i-1].count;
   s[i].first = s[i-2].first;
   s[i].last = s[i-1].last;
   if(s[i-2].last == 'A' && s[i-1].first == 'C')
     s[i].count++;
  } 
    
    
  if(s[k].count == x)
  {

    //cout<<s[k].count<<endl;
    //cout<<"first="<<s[1].first<<s[1].last<<" "<<s[1].count<<endl;
    //cout<<"second = "<<s[2].first<<s[2].last<<" "<<s[2].count<<endl;
    if(good(n,s[1].count,s[1].first,s[1].last) && good(m,s[2].count, s[2].first, s[2].last))
    {
      printString(n,s[1].count,s[1].first, s[1].last);
      cout<<endl;
      printString(m,s[2].count,s[2].first,s[2].last);
      exit(0);
    }
  }
}

char myChar(int x)
{
  if(x==0)
    return 'A';
  if(x==1)
    return 'C';
  else
    return 'K';
}
char primary(int x)
{
  return myChar(x%3);
}
char secondary(int x)
{
  return myChar(x/3);
}

int main()
{
  int k,x,n,m;
  cin>>k>>x>>n>>m;
  int n1 = (n)/2,n2 = (m)/2;
  for(int i=0; i<=n1; i++)
  {
    for(int j=0; j<=n2; j++)
    {
      for(int l=0; l<9; l++)
      {
        s[1].count = i;
        s[1].first = primary(l);
        s[1].last = secondary(l);
        for(int b=0; b<9; b++)
        {
          s[2].count = j;
          s[2].first = primary(b);
          s[2].last = secondary(b);
          if(n==1 && s[1].first != s[1].last || m==1 && s[2].first!= s[2].last)
            continue;
          else
            cal(k,x,n,m);
        }
      }
    }
  }
  cout<<"Happy new year!";
  return 0;
}
