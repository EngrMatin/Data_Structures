#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;

    int arr[row][col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j)
            {
                sum+=arr[i][j];    // Sum of primary diagonal
            }
        }
    }
    cout<<sum<<endl;

    int reqCol;
    cin>>reqCol;
    for(int i=0; i<row; i++)
    {
        cout<<arr[i][reqCol]<<" ";     //print a specific column
    }
    cout<<endl;

    int reqRow;
    cin>>reqRow;
    for(int i=0; i<col; i++)
    {
        cout<<arr[reqRow][i]<<" ";     //print a specific row
    }
    cout<<endl;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j)
            {
                continue;
            }
            if(arr[i][j]>0)
            {
                cout<<"Not Diagonal Matrix"<<endl;
                return 0;
            }
        }
    }
    cout<<"Diagonal Matrix"<<endl;

    int base;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j)
            {
                if(i==0 && j==0)
                {
                    base= arr[i][j];
                }
                else
                {
                    if(arr[i][j] != base)
                    {
                        cout<<"Not Scalar Matrix"<<endl;
                        return 0;
                    }
                }
            }

        }
    }
    cout<<"Scalar Matrix"<<endl;

    if(base==1)
    {
        cout<<"Identity Matrix"<<endl;
    }
    else
    {
        cout<<"Not Identity Matrix"<<endl;
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(arr[i][j] != arr[j][i])
            {
                cout<<"Not Symmetric Matrix"<<endl;
                return 0;
            }
        }
    }
    cout<<"Symmetric Matrix"<<endl;

    return 0;
}
