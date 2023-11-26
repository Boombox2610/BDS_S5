#include <iostream>
using namespace std;
//or use #define maxsize 10
//this defines maxsize as a macro
//the preprocessor replaces all occurrences of maxsize with the literal value 5 before the compilation process. It's a simple text replacement.
const int maxsize = 5;
//When using const int, maxsize is treated as a constant variable with a fixed value. The compiler reserves memory for maxsize and ensures that its value remains constant throughout the program
//Macros lack type checking and can lead to unexpected behavior since they are simple text substitutions.
//Constants declared with const int have a specific type, can be used in a type-safe manner, and offer better debugging capabilities.
//Macros are processed by the preprocessor, while const int involves the compiler's type-checking mechanisms.
//Using const int is generally considered safer and more modern in C++ programming.
int top = -1;
int stack[maxsize];

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

int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        cout << "\nStack is Empty";
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
    peek(); //added a peek function
    while (!isEmpty()) {
        int data = pop();
        cout << data << " ";
    }
    cout << endl;

    return 0;
}
