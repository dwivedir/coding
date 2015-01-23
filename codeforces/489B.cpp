#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
  int n,m,boys[150],girls[150];
  cin>>n;
  for(int i =1;i<=n; i++)
    cin >> boys[i];
  cin>>m;
  for(int i =1; i<=m; i++)
    cin>> girls[i];

  sort(boys+1,boys+1+n);
  sort(girls+1,girls+1+m);

  int i = 1, j = 1, count = 0;
  while( i <=n && j <= m)
  {
    if( boys[i] == girls[j] || boys[i] - girls[j] == 1 || boys[i] -girls[j] == -1)
    {
      i++; j++; count++;
    }
    else if(boys[i] < girls[j])
      i++;
    else
      j++;
  }

  cout << count;

  return 0;

}
