#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{
  int n,k;
  long long array[200005],leftSum[200005];
  long long leftMax[200005],rightMax[200005];
  cin>>n>>k;
  for(int i=1; i<=n; i++)
    cin>>array[i];
  leftSum[1] = 0;
  for(int i=1; i<=k; i++)
    leftSum[1] += array[i];
  leftMax[1] = 1;
  for(int i=2; i<=n-k+1; i++){
    leftSum[i] = leftSum[i-1] -array[i-1] + array[i+k-1];
    leftMax[i] = (leftSum[i] > leftSum[leftMax[i-1]])? i : leftMax[i-1];
  }

  rightMax[n-k+1] = n-k+1;
  for(int i=n-k; i>0; i--){
    rightMax[i] = (leftSum[i] >= leftSum[rightMax[i+1]])? i : rightMax[i+1];
  }


  long long ans = -1;
  int x,y;
  for(int i=k; i<n-k+1; i++)
  {
    long long sum = leftSum[leftMax[i-k+1]] + leftSum[rightMax[i+1]];
    if(sum>ans){
      ans = sum;
      x = leftMax[i-k+1];
      y = rightMax[i+1];
    }
  }

  cout<<x<<" "<<y;

  return 0;
}

