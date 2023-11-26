#include <iostream>
using namespace std;
const int maxsize = 100;

int Queue[maxsize];
int front = -1, rear = -1;

bool isFull(){
    return(rear == maxsize-1);
}
bool isEmpty(){
    return(front>rear || front==-1);
}

void insert(int val){
    if(!isFull()){
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear++;
        }
        Queue[rear] = val;
        cout<<endl<<Queue[rear]<<" added.";
    }
    else{
        cout<<"\nQueue is Full";
    }
}
void remove(){
    if(!isEmpty()){
        cout<<"\n"<<front<<" removed.";
        front++;
        if(front > rear){
            front = rear = 0;
        }
    }
    else{
        cout<<"\nQueue is Empty.";
    }
}
void display(){
    if(!isEmpty()){
        cout<<"\nQueue: ";
        for(int i = front; i <= rear; i++){
            cout<<" "<<Queue[i];
        }
    }
}

int main() {
    int choice, value;

    do {
        cout << "\nMenu:\n1. Insert\n2. Remove\n3. Display\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
