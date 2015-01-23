#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> first,second;
int array[500005];


int main()
{
  int n;
  long long sum = 0;
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>array[i];
    sum+= array[i];
  }
  if(n<3 || sum %3 != 0)
  {
    puts("0");
    return 0;
  }

  long long leftSum = 0;
  for(int i=1; i<=n; i++)
  {
    leftSum += array[i];
    if(leftSum == sum/3){
      first.push_back(i);
      //cout<<"first =" <<i<<endl;
    }
  }

  long long rightSum = sum;
  for(int i=1; i<=n; i++)
  {
    if(rightSum == sum/3){
      second.push_back(i);
      //cout<< "second ="<<i<<endl;
    }
    rightSum -= array[i];
  }

  long long int ans = 0;
  unsigned i =0,j=0;
  while(i<first.size() && j < second.size())
  {
    while(j<second.size() && second[j] <= first[i] +1) j++;
    if(j<second.size())
    ans += second.size()-j;
    i++;
  }

  cout<<ans;

  return 0;

}
