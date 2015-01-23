#include<iostream>
#include<stdio.h>
#include<algorithm>

#define N 105
using namespace std;
struct node
{
    int day;
    int machine;
}A[N];

bool comp(node a, node b)
{
    if(a.day < b.day)
        return 1;
    return 0;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
     {
         cin>>A[i].day;
         A[i].machine = i;
     }
    sort(A+1,A+n+1,comp);
    //cout<<A[1].day<<endl;
    int sum = 0,ans = 0;
    for(int i=1; i<=n; i++){
        sum += A[i].day;
        if(sum>k)break;
        ans++;
    }
    cout<<ans<<endl;
    for(int i=1; i<=ans; i++)
        cout<<A[i].machine<<" ";
    return 0;
}
