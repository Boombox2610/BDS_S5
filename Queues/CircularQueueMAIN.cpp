#include <iostream>
using namespace std;

class Queue {
private:
    int rear, front;
    int size;
    int *Q;

public:
    Queue(int s) : front(-1), rear(-1), size(s) {
        Q = new int[size];
    }

    ~Queue() {
        delete[] Q;
    }

    void enQueue(int value);
    void deQueue();
    void displayQueue();
};

void Queue::enQueue(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        cout << "\nOverflow.\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    Q[rear] = value;
    cout << value << " has been added to the Queue.\n";
}

void Queue::deQueue() {
    if (front == -1) {
        cout << "\nUnderflow.\n";
        return;
    }
    int value = Q[front];
    cout << "\nValue removed is: " << value << endl;
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

void Queue::displayQueue() {
    if (front == -1) {
        cout << "\nQueue is empty\n";
        return;
    }
    cout << "\nElements in circular queue are: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << Q[i] << " ";
        }
    } else {
        for (int i = front; i < size; i++) {
            cout << Q[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << Q[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int choice, s;
    bool run = true;
    cout << "Queue of how many elements: ";
    cin >> s;
    Queue circQueue(s);
    cout << "\nQueue Declared.\n";

    while (run) {
        cout << "\nWhat do you want to do:\n"
             << "Press 1 to insert [enqueue]\n"
             << "Press 2 to delete [dequeue]\n"
             << "Press 3 to view whole queue.\n"
             << "Anything else to quit.\n";
        cin >> choice;

        switch (choice) {
            case 1:
                int val;
                cout << "\nWhat value do you want to enter: ";
                cin >> val;
                circQueue.enQueue(val);
                break;
            case 2:
                circQueue.deQueue();
                break;
            case 3:
                circQueue.displayQueue();
                break;
            default:
                run = false;
                break;
        }
    }
    return 0;
}
