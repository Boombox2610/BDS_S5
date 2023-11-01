//At the call center, calls are placed in queue till they are answered by customer service agent.
//Implement the ADT of circular queue for the above application.
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int max_size;
    int *queue;
    int front, rear;

public:
    CircularQueue(int size) {
        max_size = size;
        queue = new int[max_size];
        front = rear = -1;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return (rear + 1) % max_size == front;
    }

    void enqueue(int item) {
        if (is_full()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            if (is_empty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % max_size;
            }
            queue[rear] = item;
            cout << "Call enqueued: " << item << endl;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value to indicate failure
        } else {
            int item = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % max_size;
            }
            cout << "Call dequeued: " << item << endl;
            return item;
        }
    }

    int peek() {
        if (is_empty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate failure
        } else {
            return queue[front];
        }
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue contents:" << endl;
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % max_size;
            } while (i != (rear + 1) % max_size);
            cout << endl;
        }
    }
};

int main() {
    int calls;
    cout<<"\nHow many calls on average: ";
    cin>>calls;
    CircularQueue call_center_queue(calls);
    int temp;
    bool flag = true;
    int input;
    while (flag)
    {
        cout<<"\nDo you want to add call [ENQUEUE] Press 1\nPick up call [DEQUEUE] Press 2\nTo print whole Queue, Press 3.\nPress any other number to quit.\n ";
        cin>>temp;
        switch (temp)
        {
        case 1:
            cout<<"\nEnter call number: ";
            cin>>input;
            call_center_queue.enqueue(input);
            break;
        case 2:
            call_center_queue.dequeue();
            break;
        case 3:
            call_center_queue.display();
            break;
        default:
            flag = false;
            break;
        }
    }
    
    
    call_center_queue.display();
    return 0;
}
