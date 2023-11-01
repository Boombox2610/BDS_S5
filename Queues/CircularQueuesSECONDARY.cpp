#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int capacity;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int call) {
        if (is_full()) {
            cout << "Queue is full. Cannot add more calls." << endl;
            return;
        }

        if (is_empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        queue[rear] = call;
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty. No calls to dequeue." << endl;
            return -1; // Assuming -1 represents an invalid call.
        }

        int call = queue[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return call;
    }

    int peek() {
        if (is_empty()) {
            cout << "Queue is empty. No calls to peek." << endl;
            return -1; // Assuming -1 represents an invalid call.
        }

        return queue[front];
    }

    int size() {
        if (is_empty()) {
            return 0;
        }

        if (front <= rear) {
            return rear - front + 1;
        } else {
            return capacity - front + rear + 1;
        }
    }
};

int main() {
    // Create a circular queue with a capacity of, for example, 10 calls.
    CircularQueue callQueue(10);

    // Enqueue calls to the queue.
    callQueue.enqueue(1);
    callQueue.enqueue(2);
    callQueue.enqueue(3);

    // Dequeue calls from the queue.
    cout << "Dequeued call: " << callQueue.dequeue() << endl;

    // Peek at the front of the queue.
    cout << "Front of the queue: " << callQueue.peek() << endl;

    // Check the current size of the queue.
    cout << "Queue size: " << callQueue.size() << endl;

    return 0;
}
