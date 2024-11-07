#include <iostream>
#include <string>

using namespace std;

class myStack {
private:
    int maxSize;
    int mySize;
    int top;
    char *stackArr;

public:
    myStack(int maxS, int mSize) : maxSize(maxS), mySize(mSize), top(-1) {
        stackArr = new char[mySize];
    }

    myStack() : maxSize(50), mySize(10), top(-1) {
        stackArr = new char[mySize];
    }

    ~myStack() {
        delete[] stackArr;
    }

    bool isEmpty() const {
        return (top == -1);
    }

    bool isFull() const {
        return (top >= mySize - 1);
    }

    void push(char bracket) {
        if (isFull()) {
            cout << "\nSTACK OVERFLOW\n";
            return;
        }
        stackArr[++top] = bracket;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack Empty\n";
            return;
        }
        top--;
    }

    char peek() const {
        if (isEmpty()) {
            cout << "\nStack Empty\n";
            return '\0';
        }
        return stackArr[top];
    }

    void printAll() const {
        if (isEmpty()) {
            cout << "\nStack Empty\n";
            return;
        }
        cout << "\nElements: ";
        for (int i = 0; i <= top; i++) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    string inp1;
    cout << "\nEnter a string literal: \n";
    cin >> inp1;
    int len = inp1.length();
    myStack stack1(len, len);
    for (int i = 0; i < len; i++) {
        cout << inp1[i] << " ";
        if (inp1[i] == '(' || inp1[i] == '[' || inp1[i] == '{') {
            stack1.push(inp1[i]);
            cout << " push\n";
        } else if ((inp1[i] == ')' && stack1.peek() == '(') ||
                   (inp1[i] == ']' && stack1.peek() == '[') ||
                   (inp1[i] == '}' && stack1.peek() == '{')) {
            cout << " pop\n";
            stack1.pop();
        } else if ((inp1[i] == ')' && stack1.peek() != '(') ||
                   (inp1[i] == ']' && stack1.peek() != '[') ||
                   (inp1[i] == '}' && stack1.peek() != '{')) {
            cout << "\nUnbalanced\n";
            return 0;
        } else {
            continue;
        }
    }
    if (!stack1.isEmpty()) {
        cout << "\nUnbalanced\n";
    } else {
        cout << "\nBalanced\n";
    }
    return 0;
}
