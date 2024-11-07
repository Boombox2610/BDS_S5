#include <iostream>

using namespace std;

class myStack {
private:
    int maxSize;
    int mySize;
    int top;
    int *stackArr;

public:
    myStack(int maxS, int mSize) : maxSize(maxS), mySize(mSize), top(-1) {
        stackArr = new int[mySize];
    }

    myStack() : maxSize(50), mySize(10), top(-1) {
        stackArr = new int[mySize];
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

    void push(int num) {
        if (isFull()) {
            cout << "\nSTACK OVERFLOW\n";
            return;
        }
        stackArr[++top] = num;
    }

    int pop() {
        if (isEmpty()) {
            cout << "\nStack Empty\n";
            return -1;
        }
        return stackArr[top--];
    }

    int peek() const {
        if (isEmpty()) {
            cout << "\nStack Empty\n";
            return -1;
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
    void sortStack() {
    if (!isEmpty()) {
        int temp = pop();
        sortStack();
        sortedInsert(temp);
    }
    }

    void sortedInsert(int num) {
        if (isEmpty() || peek() < num) {
            push(num);
        } else {
            int temp = pop();
            sortedInsert(num);
            push(temp);
        }
    }
};

int main() {
    myStack stack;

    int choice;
    int value;

    cout << "Welcome to the Stack Program\n";

    do {
        // Display menu options
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print All\n";
        cout << "5. Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "Top value: " << value << endl;
                }
                break;
            case 4:
                stack.printAll();
                break;
            case 5:
                stack.sortStack();
                cout << "Stack sorted\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
