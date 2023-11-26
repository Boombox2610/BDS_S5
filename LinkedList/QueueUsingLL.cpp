#include <iostream>
using namespace std;

// Node structure to represent a node in the queue
struct Node {
    int value;
    Node* next;

    // Constructor to initialize a node with a given value
    Node(int val) : value(val), next(NULL) {}
};

class Queue {
private:
    Node *front; // Pointer to the front of the queue
    Node *rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(NULL), rear(NULL) {}

    // Function to enqueue a value into the queue
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\nEnqueued " << newNode->value << endl;
    }

    // Function to dequeue a value from the queue
    int dequeue() {
        if (front == NULL) {
            cout << "\nEmpty\n";
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = temp->value;
        front = temp->next;
        delete temp;
        return dequeuedValue;
    }

    // Function to display the contents of the queue
    void display() {
        if (front == NULL) {
            cout << "\nEmpty\n";
            return;
        }
        Node* temp = front;
        cout << "\nElements are: ";
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    char choice;

    do {
        cout << "Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case '2': {
                int dequeuedValue = queue.dequeue();
                if (dequeuedValue != -1) {
                    cout << "Dequeued: " << dequeuedValue << endl;
                }
                break;
            }
            case '3':
                queue.display();
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
