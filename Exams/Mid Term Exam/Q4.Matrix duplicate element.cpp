#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin>>m>>n;

    int arr[m][n];
    int la[m*n], k=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
            la[k] = arr[i][j];
            k++;
        }
    }

    for(int i=0; i<m*n; i++)
    {
        for(int j=i+1; j<m*n; j++)
        {
            if(la[i]==la[j])
            {
                la[j]= -1;
            }
        }
    }

    for(int i=0; i<m*n; i++)
    {
        cout<<la[i]<<" ";
        if((i+1)%m == 0)
        {
            cout<<endl;
        }
    }

    return 0;
}
