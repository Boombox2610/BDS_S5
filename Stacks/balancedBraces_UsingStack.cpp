#include <iostream>
#include <cstring>
using namespace std;

const int maxsize = 100;
int top = -1;
char stack[maxsize];

bool isFull() {
    return top == maxsize - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(char var) {
    if (!isFull()) {
        top++;
        stack[top] = var;
    } else {
        cout << "Stack is full." << endl;
    }
}

char pop() {
    char data;
    if (!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        cout << "Could not retrieve data, Stack is empty." << endl;
        return -1;
    }
}

bool balance(char stringInput[]) {
    for (int i = 0; i < strlen(stringInput); i++) {
        char element = stringInput[i];
        if (element == '(' || element == '{' || element == '[') {
            push(element);
        } else if (element == ')' || element == '}' || element == ']') {
            if (top < 0) {
                return false;
            }
            char poppedVal = pop();
            if ((element == ')' && poppedVal != '(') || (element == '}' && poppedVal != '{') ||
                (element == ']' && poppedVal != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char charArray[maxsize];
    cout << "\nEnter string of max size " << maxsize << ": ";
    cin >> charArray;
    cout << endl;

    if (balance(charArray)) {
        cout << "Expression is Balanced." << endl;
    } else {
        cout << "Expression is NOT Balanced." << endl;
    }

    return 0;
}
