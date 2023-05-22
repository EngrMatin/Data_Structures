#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    int sum=0;
    for(int j=0; j<=n/2; j++)
    {
        sum += arr[0][j];
    }
    //cout<<"Sum1= "<<sum<<endl;

    for(int j=0; j<n; j++)
    {
        sum += arr[n/2][j];
    }
    //cout<<"Sum2= "<<sum<<endl;

    for(int j=n/2; j<=n; j++)
    {
        sum += arr[n-1][j];
    }
    //cout<<"Sum3= "<<sum<<endl;

    for(int i=0; i<n; i++)
    {
        if(i!=0 && i!=n/2 && i!=n-1)
        {
            sum += arr[i][n/2];
        }
    }
    //cout<<"Sum4= "<<sum<<endl;

    for(int i=0; i<n/2; i++)
    {
        sum += arr[i][n-1];
    }
    //cout<<"Sum5= "<<sum<<endl;

    for(int i=n/2+1; i<n; i++)
    {
        sum += arr[i][0];
    }

    cout<<sum<<endl;

    return 0;
}
