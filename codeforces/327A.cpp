#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  int max = -1, one[150],zero[150],n,x;
  cin>> n;
  one[0]=zero[0] = 0;
  for(int i=1; i<=n; i++)
  {
    cin>> x;
    one[i] = one[i-1];
    zero[i] = zero[i-1] ;
    if(x)
      one[i]++;
    else
      zero[i]++;
  }

  int maxi,maxj;
  for(int i =1; i<= n; i++)
    for(int j = i; j <= n; j++)
    {
      int y = zero[j] - zero[i-1] - one[j] + one[i-1];
      if(y>max)
      {
        max = y;
        maxi = i;
        maxj = j;
      }
    }

  //cout<< max<< endl;
  if(max==-1)
    cout<< (one[n]-1);
  else
    cout<< (zero[maxj] - zero[maxi-1] + one[maxi-1] + one[n] - one[maxj]);

  return 0;

}
