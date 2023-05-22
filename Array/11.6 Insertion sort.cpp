#include<bits/stdc++.h>
using namespace std;

void printArray(int array[], int n);

int main()
{
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    cout<<endl;
    cout<<"Before Sorting: ";
    printArray(array, n);
    cout<<endl;

    for(int i=1; i<n; i++)
    {
        int key= array[i];

        cout<<endl<<"i: "<<i<<" Key: "<<key<<endl;
        int j=i-1;
        while(array[j]>key && j>=0)
        {
            array[j+1]= array[j];
            printArray(array, n);
            j--;
        }
        array[j+1]= key;
        printArray(array, n);
    }

    cout<<endl;
    cout<<"After Insertion Sorting: ";
    printArray(array, n);
    cout<<endl;

    return 0;
}

void printArray(int array[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
