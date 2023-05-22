#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[5]={10, 8, 1, 2, 5};
    int preSum[5];

    preSum[0]=array[0];
    for(int i=0; i<5; i++)
    {
        preSum[i]= array[i]+preSum[i-1];
    }

    for(int i=0; i<5; i++)
    {
        cout<<preSum[i]<<" ";;
    }

    return 0;
}
