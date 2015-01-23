#include<iostream>
#include<stdio.h>
typedef long long ll;
using namespace std;

ll parent(ll x){
    return (x+1)/2;
}

bool L(ll x)
{
    ll p = parent(x);
    return (x == (2*p -1));
}

bool R(ll x)
{
    ll p  = parent(x);
    return (x == 2*p);
}

ll size(int h)
{
    h++;
    ll y = (long long)1<<h;
    return y-1;
}

int main()
{
    int h;
    ll n,first,second;
    long long ans = 0;
    cin>>h>>n;
    for(int i = h; i>1; i--,n = parent(n))
    {
        first = parent(n);
        ans ++;
        if(L(n)&&L(first) || R(n)&&R(first))
            ans += size(h-i);
    }
    ans ++;
    if(R(n))
        ans += size(h-1);
    cout<<ans;
    return 0;
}

