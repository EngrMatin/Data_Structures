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

    cout<<"After heapify: ";
    printArray(array, n);

    heapSort(array, n);
    cout<<"After heapsort: ";
    printArray(array, n);

    return 0;
}

void heapify(int array[], int n, int current)
{
    int largest = current;
    int leftChild = 2*current + 1;
    int rightChild = 2*current + 2;

    if(leftChild < n && array[leftChild] > array[largest])
    {
        largest = leftChild;
    }

    if(rightChild < n && array[rightChild] > array[largest])
    {
        largest = rightChild;
    }

    if(largest != current)
    {
        swap(array[current], array[largest]);
        heapify(array, n, largest);
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
    cout<<endl;
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
        //cout<<"After swap: ";
        //printArray(array, n);
        heapify(array, i, 0);
        //cout<<"After heapify: ";
        //printArray(array, n);
    }
}

/*

9
2 10 1 5 4 8 3 8 7



*/
