#include <iostream>
using namespace std;

// Node structure to represent a node in the stack
struct Node {
    int value;
    Node* next;

    // Constructor to initialize a node with a given value
    Node(int val) : value(val), next(NULL) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(NULL) {}

    // Function to push a value onto the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "\nPushed: " << newNode->value << endl;
    }

    // Function to pop a value from the stack
    int pop() {
        if (top == NULL) {
            cout << "\nMT\n"; // MT stands for "Empty" (Empty stack)
            return -1;
        }
        int poppedValue = top->value;
        Node* temp = top;
        top = temp->next;
        delete temp;
        return poppedValue;
    }

    // Function to display the contents of the stack
    void display() {
        if (top == NULL) {
            cout << "\nMT\n"; // MT stands for "Empty" (Empty stack)
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    int peek(){
        if (top == NULL){
            cout<<"\nEmpty"; return;
        }
        return top->value;
    }
};

int main() {
    Stack stack;
    char choice;

    do {
        cout << "Menu:\n1. Push\n2. Pop\n3. Display\n4. Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case '2': {
                int poppedValue = stack.pop();
                if (poppedValue != -1) {
                    cout << "Popped: " << poppedValue << endl;
                }
                break;
            }
            case '3':
                stack.display();
                break;
            case '4':
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
