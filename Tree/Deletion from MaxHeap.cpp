#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;                 // Initialize largest as root
    int l = 2 * i + 1;               // left = 2*i + 1
    int r = 2 * i + 2;               // right = 2*i + 2

    if(l<n && arr[l]>arr[largest])   // If left child is larger than root
    {
        largest = l;
    }

    if(r<n && arr[r]>arr[largest])   // If right child is larger than largest so far
    {
        largest = r;
    }

    if(largest != i)                     // If largest is not root
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);         // Recursively heapify the affected sub-tree
    }
}

void deleteRoot(int arr[], int &n)
{
    int lastElement = arr[n - 1];        // Get the last element

    arr[0] = lastElement;                // Replace root with last element

    n = n-1;                             // Decrease size of heap by 1

    heapify(arr, n, 0);                  // heapify the root node
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4
    int arr[] = { 10, 5, 3, 2, 4 };

    int n = sizeof(arr)/sizeof(arr[0]);

    deleteRoot(arr, n);
    printArray(arr, n);

    return 0;
}
