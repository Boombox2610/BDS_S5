#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int size;
    int *Q;

public:
    Queue(int s) : front(-1), rear(-1), size(s) {
        Q = new int[size];
    }

    ~Queue() {
        delete[] Q;
    }

    bool isFull() const {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() const {
        return front == -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "\nOVERFLOW";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        Q[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nUNDERFLOW";
            return;
        }
        cout << "\n" << Q[front] << " removed.";
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "\nEmpty";
            return;
        }
        if (rear < front) {
            for (int i = front; i < size; i++) {
                cout << Q[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << Q[i] << " ";
            }
        } else {
            for (int i = front; i <= rear; i++) {
                cout << Q[i] << " ";
            }
        }
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);

    while (true) {
        cout << "\n\nQueue Operations Menu:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, please try again.";
        }
    }
}
