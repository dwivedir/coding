#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int L[6],R[6],position[6];
bool good(int index, int b, int place)
{
  if(place == 0)
    return R[index] > b;
  else if(place == 1)
    return b>=L[index] && b<=R[index];
  else
    return b>L[index];
}
int main()
{
  double ans = 0,all = 1;
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>L[i]>>R[i];
    all *= R[i]-L[i]+1;
  }
  int count[3] = {0};
  int times = pow(3,n);
  for(int b=1; b<=10000; b++){
    double trueCase = 0;
    for(int i=0; i<times; i++)
    {
      int x = i;
      bool r = 1;
      count[0] = count[1] = count[2] = 0;
      for(int j=1; j<=n; j++)
      {
        int place = x%3;
        position[j] = place;
        count[place]++;
        r &= good(j,b,place);
        x /= 3;
      }
      if(!r) continue;

      if(count[0] == 1 && count[1] >=1 || count[0] == 0 && count[1] >= 2){
        double multiple = 1;
        for(int j=1; j<=n; j++)
        {
          if(position[j] == 0)
            multiple *= R[j] - max(b,L[j]-1);
          else if(position[j] == 2)
            multiple *= min(b,R[j]+1) - L[j];
        }
        trueCase += multiple;
      }
    }
    ans += b*(double)trueCase/all;
  }

  printf("%0.10f",ans);
  return 0;
}
