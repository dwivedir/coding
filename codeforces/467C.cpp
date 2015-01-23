#include<iostream>
#include<stdio.h>

using namespace std;
long long int mat[5005][5005];

int main()
{ 
  long long int array[5005],sum[5005];
  int n,m,k;
  sum[0] = 0;
  cin>>n>>m>>k;

  for(int i=1; i<=n; i++)
  {
    cin>>array[i];
    sum[i] = sum[i-1] + array[i];
  }

  for(int i=0; i<=k; i++)
    mat[0][i] = 0;
  for(int i=1; i<=n; i++)
    mat[i][0] = 0;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++)
    {
      mat[i][j] = mat[i-1][j];
      if(i-m>=0)
        mat[i][j] = max(mat[i][j], mat[i-m][j-1] + sum[i] - sum[i-m]);
      //cout<<mat[i][j]<<" ";
    }
    //cout<<endl;
  }

  cout<< mat[n][k];

  return 0;
}
