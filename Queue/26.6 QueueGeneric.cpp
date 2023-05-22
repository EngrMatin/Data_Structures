#include<bits/stdc++.h>
#include"MyQueueGeneric.h"
using namespace std;

int main()
{
    Queue <int> q;

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int chk;
        cin>>chk;
        q.push(chk);
    }

    if(!q.empty())
    {
        cout<<q.Front()<<endl;
    }

    if(!q.empty())
    {
        cout<<q.Back()<<endl;
    }

    while(!q.empty())
    {
        cout<<q.pop()<<endl;
    }


    return 0;
}
