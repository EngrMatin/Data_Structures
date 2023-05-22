#include <bits/stdc++.h>
using namespace std;

void countFrequency(int *arr, int size){

    for (int i = 0; i < size; i++){
        int flag = 0;
        int count = 0;

        // Counting of any element has to be delayed to its last occurrence
        for (int j = i+1; j < size; j++){
            if (arr[i] == arr[j]){
                flag = 1;
                break;
            }
        }

        // The continue keyword is used to end the current iteration
        // in a for loop (or a while loop), and continues to the next iteration
        if (flag == 1)
            continue;

        for(int j = 0;j<=i;j++){
            if(arr[i]==arr[j])
                count +=1;
        }

        cout << arr[i] << ": " << count << endl;
    }
}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}
