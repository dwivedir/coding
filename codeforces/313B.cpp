#include<iostream>

using namespace std;
char str[100005];
int array[100005];
int main()
{
  int m;
  cin>> (str+1);
  for(int i= 2; str[i]; i++)
    if(str[i] == str[i-1])
      array[i] = array[i-1] + 1;
    else
      array[i] = array[i-1];

  cin>>m;
  int l,r;
  while(m--)
  {
    cin >> l >> r;
    cout<< (array[r] - array[l]) << endl;
  }

  return 0;
}
