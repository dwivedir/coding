#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> list[27];
struct node
{
  char value;
  int disc;
  int finish;
  int visited;
}graph[27];

int index(char x)
{
  if(x=='\0')
    return 0;
  else
    return x-'a'+1;
}
int t;
bool cycle = false;
char str[105][105];
char ans[30];
int ansIt=25;
void dfs(int u)
{
  t++;
  graph[u].disc = t;
  graph[u].visited = 1;
  for(unsigned i=0; i<list[u].size(); i++)
  {
    int v = list[u][i];
    if(graph[v].visited == 1)
      cycle = 1;
    else if(graph[v].visited == 0)
      dfs(v);
  }
  t++;
  graph[u].visited = 2;
  graph[u].finish = t;
  if(graph[u].value != '\0')
    ans[ansIt--] = graph[u].value;
}
int main()
{

  graph[0].value = '\0';
  for(int i=1; i<=26; i++){
    graph[i].value = 'a'+i-1;
    graph[i].visited = 0;
    list[0].push_back(i);
  }

  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>(str[i]+1);
  for(int i=2; i<=n; i++)
  {
    int k=1;
    while(str[i][k] && str[i-1][k] && str[i][k] == str[i-1][k])
      k++;
    if(str[i][k] == str[i-1][k])
      continue;
    //cout<<str[i-1][k]<<"->"<<str[i][k]<<endl;
    int x = index(str[i-1][k]);
    int y = index(str[i][k]);
    list[x].push_back(y);
  }

  t = 0;
  for(int i=0; i<=26; i++)
    if(graph[i].visited == 0)
      dfs(i);
  if(cycle)
    cout<<"Impossible";
  else
  {
    cout<<ans;
  }
  return 0;
}
