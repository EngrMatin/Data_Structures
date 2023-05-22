#include<bits/stdc++.h>

using namespace std;

template<typename T> T myMax(T a, T b);

int main()
{
    cout<<myMax<int>(3,7)<<endl;         //functionName <dataType>(parameter)
    cout<<myMax<float>(3.5,7.8)<<endl;
    cout<<myMax<char>('a','f')<<endl;


    return 0;
}

template<typename T> T myMax(T a, T b)
{
    return (a>b)? a:b;
}
