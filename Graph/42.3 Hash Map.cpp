#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> M;

    M[3] = 9;
    M[2] = 5;
    M.insert(make_pair(1,4));

    cout<<"Key"<<" | "<<"Value"<<endl;
    for(auto i: M)
    {
        cout<<i.first<<"   | "<<i.second<<endl;
    }
    cout<<endl;

    unordered_map<int,int> UM;

    UM[3] = 9;
    UM[2] = 5;
    UM.insert(make_pair(1,4));

    cout<<"Key"<<" | "<<"Value"<<endl;
    for(auto i: UM)
    {
        cout<<i.first<<"   | "<<i.second<<endl;
    }

    return 0;
}
