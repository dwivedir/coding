#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
bool visited[305];
vector<int> v;
vector<int> pos;
char A[305][305];
void dfs(int index, int size, int array[])
{
  v.push_back(array[index]);
  pos.push_back(index);
  visited[index] = 1;
  for(int i=1; i<=size; i++){
    if(A[index][i] == '1' && visited[i] == 0){
      dfs(i,size,array);
    }
  }

}
int main()
{
  int n,array[305];
  cin>>n;
  for(int i=1; i<=n;i++){
    cin>>array[i];
    visited[i] = 0;
  }

  for(int i= 1;i<=n; i++)
    scanf("%s",A[i]+1);

  for(int i=1; i<=n; i++)
  {
    if(visited[i] == 0)
    {
      dfs(i,n,array);
      sort(v.begin(),v.end());
      sort(pos.begin(),pos.end());
      for(unsigned j = 0; j< v.size(); j++)
      {
        //cout<<v[j]<" ";
        array[pos[j]] = v[j];
      }
      //cout<<endl;
      v.clear();
      pos.clear();
    }
  }


  for(int i=1; i<=n; i++)
    cout<<array[i] << " ";

  return 0;

}
