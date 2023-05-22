#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int pos[n], top=0;
    int prev[n], next[n];
    for(int i=1; i<=n; i++)
    {
        cin>>prev[i]>>next[i];
        if(prev[i]==0)
        {
            pos[++top]=i;
        }
    }

    for(int i=top; i>=2; i--)
    {
        int x= pos[i];
        while(next[x] != 0)
        {
            x = next[x];
        }
        next[x] = pos[i-1];
        prev[pos[i-1]] = x;
    }
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<prev[i]<<" "<<next[i]<<endl;
    }

    return 0;
}

