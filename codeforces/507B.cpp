#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
    long long r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    long double sq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    sq = sqrt(sq);
    sq /= (2*r);
    cout<<ceill(sq);
    return 0;
}
