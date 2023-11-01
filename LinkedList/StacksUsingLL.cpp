#include <iostream>
//stack inplementation using LL
using namespace std;
struct Node{
    int value;
    Node* next;
    Node(int val):value(val), next(NULL){};
};
struct Stack{
    Node *top;
    Stack(){
        top = NULL;
    }
    void push(int val){
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout<<"\nPushed: "<<newNode->value<<endl;
    }
    int pop(){
        if(top == NULL){
            cout<<"\nMT\n";
            return -1;
        }
        int poper = top->value;
        Node *temp = top;
        top = temp->next;
        delete temp;
        return poper;
    }
    void display(){
        if(top == NULL){
            cout<<"\nMT\n";
        }
        Node *temp = top;
        while(temp != NULL){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
  Stack stack;
  char choice;

  do {
    std::cout << "Menu:\n1. Push\n2. Pop\n3. Display\n4. Quit\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case '1': {
        int value;
        std::cout << "Enter a value to push: ";
        std::cin >> value;
        stack.push(value);
        break;
      }
      case '2': {
        int poppedValue = stack.pop();
        if (poppedValue != -1) {
          std::cout << "Popped: " << poppedValue << std::endl;
        }
        break;
      }
      case '3':
        stack.display();
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
