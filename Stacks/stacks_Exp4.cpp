#include <iostream>
using namespace std;

const int maxsize = 5;
int top = -1;
int stack[5];

bool isFull() {
    return top == maxsize - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int var) {
    if (!isFull()) {
        top++;
        stack[top] = var;
    } else {
        cout << "Stack is full." << endl;
    }
}

int pop() {
    int data;
    if (!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        cout << "Could not retrieve data, Stack is empty." << endl;
        return -1;
    }
}

int main() {
    int i;
    cout << "\nEnter " << maxsize << " elements: ";
    for (i = 0; i < maxsize; i++) {
        int k;
        k = 0;
        cout << "\nValue of element " << i + 1 << ": ";
        cin >> k;
        push(k);
    }

    for (i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    while (!isEmpty()) {
        int data = pop();
        cout << data << " ";
    }
    cout << endl;

    return 0;
}
