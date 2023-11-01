#include <iostream>

using namespace std;


class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int cap) {
        capacity = cap;
        size = 0;
        front = 0;
        rear = cap - 1;
        arr = new int[cap];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "\nDeque Full\n";
            return;
        }

        front = (front - 1 + capacity) % capacity;
        arr[front] = val;
        size++;
        cout << "\nInserted " << val << " at the front";
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "\nDeque Full\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        cout << "\nInserted " << val << " at the rear";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "\nUnderflow - Deque is empty\n";
            return;
        }

        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << "\nRemoved " << val << " from the front";
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "\nUnderflow - Deque is empty\n";
            return;
        }

        int val = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        size--;
        cout << "\nRemoved " << val << " from the rear";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }

        cout << "\nElements are: ";
        int count = 0;
        int i = front;

        while (count < size) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
    }

    ~Deque() {
        delete[] arr;
    }
};

int main(){


    return 0;
}