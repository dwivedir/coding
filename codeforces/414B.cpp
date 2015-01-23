#include<iostream>
#include<vector>
#define mod 1000000007

using namespace std;
vector<int> divisor[2005];
long long int mat[2005][2005];
int main()
{
  int n,k;
  cin>>n>>k;
  for(int i =1; i<=n; i++)
    mat[i][1] = 1;
  for(int j=1; j<=k; j++)
    mat[1][j] = 1;
  
  for(int i =1; i<= n; i++)
  {
    for(int j=i; j<=n; j+=i)
      divisor[j].push_back(i);
  }

  for(int i=2; i<=n; i++)
    for(int j=2; j<=k; j++)
    {
      mat[i][j] = 0;
      for(unsigned k=0; k<divisor[i].size(); k++)
      {
        mat[i][j] += mat[divisor[i][k]][j-1];
        mat[i][j] %= mod;
      }
    }

  long long int ans = 0;
  for(int i=1; i<=n; i++)
  {
    ans += mat[i][k];
    ans %= mod;
  }

  cout<<ans;

  return 0;

}
