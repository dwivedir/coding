#include<iostream>

using namespace std;

int dp[4005];

int maximum(int n, int a, int b, int c)
{
  //cout<< "n = " << n << endl;
  if(n == 0)
    return 0;
  else if(n < a && n<b && n<c)
    return -1;
  else if(dp[n] != -1) return dp[n];
  else
  {
    int x = maximum(n-a,a,b,c);
    int y = maximum(n-b,a,b,c);
    int z = maximum(n-c,a,b,c);
    //if(n == 5)
    //cout<<"at n =5 x ="<< x << "y = "<<y << "z = "<<z<<endl;
    if(x == -1 && y == -1 && z == -1)
      dp[n] = -1;
    else
      dp[n] = 1 + max(max(x,y),z);
    return dp[n];
  }
}
int main()
{
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  //cout << a << b << c;
  for(int i =1; i<=n; i++)
    dp[i] = -1;

  cout<< maximum(n,a,b,c)<<endl;
  //for(int i =1; i<= n; i++)
    //cout<< dp[i]<<" "<<endl;

  return 0;
}
