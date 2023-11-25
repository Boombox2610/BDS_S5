#include <iostream>
#include <string>
//Implementation of Sequential Search and binary search
using namespace std;

void sequentialSearch(int *arr, int len, int val){
    int counter = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] == val){
            counter++;
        }
    }
    if(counter == 0){
        cout<<"\nElement not found in array.";
    }
    else{
        cout<<"\nElement found at index: ";
        for(int i = 0; i < len; i++){
            if(arr[i] == val){
                cout<< i <<" ";
            }
        }
    }
    cout<<endl;
}

void binarySearch(int *arr, int len, int val){
    int low, mid, high;
    low = 0;
    high = len;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == val){
            cout<<"\nFound "<<val<<" at index: "<<mid;
            return;
        }
        if(arr[mid] < val){
            low = mid + 1;
        }
        else{ //arr[mid] > val
            high = mid - 1;
        }
    }
    cout<<"\nNot found.";
}
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
    
    bubbleSort(arr, len);
    
    for(int i = 0; i < len; i++){
        cout<<"\n value of element "<<i + 1<<": "<<arr[i];
    }
    sequentialSearch(arr, len, find);
    binarySearch(arr, len, find);
    return 0;
}