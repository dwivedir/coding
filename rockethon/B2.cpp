#include<iostream>
#include<stdio.h>

using namespace std;

int str[100];
void fun(int index, int i, int j, int n,long long m)
{
    if(i==j)
    {
        str[i] = index ;
        return;
    }
    long long count = (long long)1<<(n-index-1);
    if(m<=count)
    {
        str[i] = index ;
        fun(index+1,i+1,j,n,m);
    }
    else
    {
        str[j] = index ;
        fun(index+1,i,j-1,n,m-count);
    }
}

int main()
{
    int n;
    long long m;
    cin>>n>>m;
    fun(1,1,n,n,m);
    for(int i=1; i<=n; i++)
      cout<<str[i]<<" ";
    return 0;
}
