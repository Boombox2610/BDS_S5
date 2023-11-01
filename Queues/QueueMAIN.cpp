#include <iostream>
using namespace std;
class Queue{
    int rear, front;
    int size;
    int *Q;
    public:
    Queue(int s){
        front = rear = -1;
        size = s;
        Q = new int[s];
    }
    void enqueue(int val);
    void dequeue();
    void display();
};
void Queue::enqueue(int val){
    if(front == -1){
        front = rear = 0;
    }
    if(rear == size - 1){
        cout<<"\nQueue Full\n";
        return;
    }
    Q[rear] = val;
    rear++;
    cout<<"\nInserted "<<val;
}
void Queue::dequeue(){
    if(front == -1 || front > rear){
        cout<<"\nUnderflow";
        return;
    }
    cout<<endl<<Q[front]<<" removed.";
    front++;
}
void Queue::display(){
    if(front == -1){
        cout<<"\nUnderflow";
        return;
    }
    cout<<endl<<"Elements are: ";
    for(int i = front; i < rear; i++){
        cout<<Q[i]<<" ";
    }
}
int main(){
    Queue q(10);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}