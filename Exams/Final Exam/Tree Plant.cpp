#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y;
    cin>>y;

    long long ans;
    if(y==1)
    {
        ans = 1;
    }
    else
    {
        ans = 2*(pow(4,y-2));
    }

    cout<<ans<<endl;

    return 0;
}

