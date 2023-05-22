#include<bits/stdc++.h>
using namespace std;

void printArray(int array[], int n);

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout<<"Before Sort: "<<endl;
    printArray(arr, n);

    // Step 1: Finding Max
    int max = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Step 2: Initialization of Count array
    int count[max+1];
    for(int i=0; i<=max; i++)
    {
        count[i] = 0;
    }

    // Step 3: Frequency Calculation
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    cout<<"Frequency: "<<endl;
    printArray(count, max+1);

    // Step 4: Cumulative Sum
    for(int i=0; i<=max; i++)
    {
        count[i] += count[i-1];
    }

    cout<<"Cumulative Frequency: "<<endl;
    printArray(count, max+1);

    // Step 5: Final Array -- Backward Traversal of Basic Array
    int final[n];
    for(int i=0; i<n; i++)
    {
        count[arr[i]]--;
        int k= count[arr[i]];
        final[k]= arr[i];
    }

    cout<<"Final sorted array: "<<endl;
    printArray(final, n);

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
