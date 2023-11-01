#include <iostream>
#include <string>
using namespace std;
struct Node{
    int value;
    Node *next;
    Node(int val): value(val), next(NULL){};
};
struct Queue{
    Node *front;
    Node *rear;
    Queue(){
        front = rear = NULL;
    }
    void enqueue(int val){
        Node *newNode = new Node(val);
        if(front==NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    cout<<"\nEnqueued "<<newNode->value<<endl;
    }
    int dequeue(){
        if(front == NULL){
            cout<<"\nEmpty\n";
            return -1;
        }
        Node *temp = front;
        int dQ = temp->value;
        front = temp->next;
        delete temp;
        return dQ;
    }
    void display(){
        if(front == NULL){
            cout<<"\nEmpty\n";
            return;
        }
        Node *temp = front;
        cout<<"\nElements are: ";
        while(temp!= NULL){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
  Queue queue;
  char choice;

  do {
    std::cout << "Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case '1': {
        int value;
        std::cout << "Enter a value to enqueue: ";
        std::cin >> value;
        queue.enqueue(value);
        break;
      }
      case '2': {
        int dequeuedValue = queue.dequeue();
        if (dequeuedValue != -1) {
          std::cout << "Dequeued: " << dequeuedValue << std::endl;
        }
        break;
      }
      case '3':
        queue.display();
        break;
      case '4':
        std::cout << "Quitting the program." << std::endl;
        break;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (choice != '4');

  return 0;
}
