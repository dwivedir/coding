#include<bits/stdc++.h>
using namespace std;
int visited[10000];
vector<int> list;
void dfs(int x, int n)
{
  if(visited[x]) return;
  for(int i= 1; i<=n; i++)
    dfs

