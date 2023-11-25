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