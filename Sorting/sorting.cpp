#include <iostream>
#include <string>
//Implementation of Sequential Search and binary search
using namespace std;
void bubbleSort(int *arr, int len){
    int temp = 0;
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void selectionSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertionSort(int *arr, int len) {
    int temp, j;
    for (int i = 1; i < len; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//------------------------------------------RADIX-------------------------------

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int n, int exp) {
    const int RANGE = 10; // Range of digits is 0 to 9

    int output[n];
    int count[RANGE] = {0};

    // Count occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < RANGE; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}



int main(){
    int len;
    cout<<"\nEnter length of array: ";
    cin>>len;
    int arr[len];
    cout<<"Enter elements of array: \n";
    for(int i = 0; i < len; i++){
        cout<<"Enter value of element "<<i + 1<<": ";
        cin>>arr[i];
    }
    int find;
    cout<<"\nFind what element to find using sequential search: ";
    cin>>find;
    
    insertionSort(arr, len);
    bubbleSort(arr, len);
    selectionSort(arr, len);
    for(int i = 0; i < len; i++){
        cout<<"\n value of element "<<i + 1<<": "<<arr[i];
    }

    return 0;
}
