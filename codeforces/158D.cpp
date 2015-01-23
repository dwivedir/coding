#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

vector<int> divisor;
int main()
{
  int n;
  cin >> n;

  for(int i=1; i*i<= n; i++)
  {
    if(n%i == 0)
    {
      divisor.push_back(i);
      if(n/i > sqrt(n))
        divisor.push_back(n/i);
    }
  }

  int array[n+5];
  for(int i=1; i<=n; i++)
    {
      cin>> array[i];
    }
  int max = -1e9, sum;
  for(unsigned i= 0; i<divisor.size(); i++)
  {
    //cout<< "divisor = " << divisor[i] << endl;
    if(divisor[i] < 3) continue;
    for(int j= 1; j<= n/divisor[i]; j++)
    {
      sum = 0;
      for(int k=j; k<=n; k+= n/divisor[i])
      {
        sum += array[k];
      }
      if(sum > max)
        max = sum;
    }
  }

  cout<<max;
  return 0;
}
