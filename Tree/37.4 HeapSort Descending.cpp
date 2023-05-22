#include<bits/stdc++.h>
using namespace std;

void heapify(int array[], int n, int current);
void swap(int *a, int *b);
void printArray(int array[], int size);
void heapSort(int array[], int size);

int main()
{
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    cout<<"Before heapify: ";
    printArray(array, n);

    int nonLeafStart = (n/2)-1;
    for(int i=nonLeafStart; i>=0; i--)
    {
        heapify(array, n, i);
    }

    cout<<"After heapify1: ";
    printArray(array, n);

    heapSort(array, n);
    cout<<"After heapsort: ";
    printArray(array, n);

    return 0;
}

void heapify(int array[], int n, int current)
{
    int smallest = current;
    int leftChild = 2*current + 1;
    int rightChild = 2*current + 2;

    if(leftChild < n && array[leftChild] < array[smallest])
    {
        smallest = leftChild;
    }

    if(rightChild < n && array[rightChild] < array[smallest])
    {
        smallest = rightChild;
    }

    if(smallest != current)
    {
        swap(array[current], array[smallest]);
        heapify(array, n, smallest);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int size)
{
    //cout<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int array[], int n)
{
    for(int i= n-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        cout<<"After swap:     ";
        printArray(array, n);
        heapify(array, i, 0);
        cout<<"After heapify2: ";
        printArray(array, n);
    }
}

/*

6
20 50 40 5 30 15

*/
