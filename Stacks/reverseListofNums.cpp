#include <iostream>
using namespace std;

const int maxsize = 10;
int stack[maxsize];
int top = -1;

bool isEmpty(){
    return(top == -1);
}
bool isFull(){
    return(top == maxsize-1);
}

void push(int val){
    if(!isFull()){
        stack[++top] = val;
    }
    else{
        cout<<"\nFULL";
    }
}
int pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    else{
        return -1;
    }
}

int main(){
    int size;
    cout<<"\nEnter number of elements in array MAXSIZE 10: ";
    cin>>size;
    for(int i = 0; i < size; i++){
        int tempInt;
        cout<<"\nEnter number "<<i + 1<<": ";
        cin>>tempInt;
        push(tempInt);
    }
    int arr[size];
    //reversing
    for(int i = 0; i < size; i++){
        arr[i] = pop();
    }
    //reversed array
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
