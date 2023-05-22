#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int n;
        long long c;
        cin>>n>>c;

        int array[n];
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>array[i];
            sum += array[i];
        }

        if(2*sum <= c)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}

