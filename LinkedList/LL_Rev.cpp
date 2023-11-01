#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    //parameterized constructors
    Node(int val = 0): value(val), next(NULL){};
    Node(int val, Node* tempNext): value(val), next(tempNext){};
};

class LinkedList{
    Node* head;

    public:
    LinkedList(): head(NULL){};
    void insertAtStart(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
    void insertAtNthPosition(int val, int n){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        if(n == 1){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        --n;
        for(int i = 0; i < n - 1 && temp!= NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"INVALID";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteAtStart(){
        if(head == NULL){
            cout<<"\nList is empty\n";
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void deleteAtEnd(){
        if(head == NULL){
            cout<<"\nList is empty\n";
            return;
        }
        else{
            Node *temp, *prev;
            temp = prev = head;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
    }
    void deleteByVal(int val){
        if(head == NULL){
            cout<<"\nList is empty\n";
            return;
        }
        Node *temp = head;
        if(temp != NULL && temp->value == val){
            head = temp->next;
            delete temp;
            return;
        }
        else{
            Node *current = head;
            while(temp != NULL && temp->value != val){
                current = temp;
                temp = temp->next;
            }
            if(!temp){
                cout<<"\nValue Not Found.\n";
                return;
            }
            current->next = temp->next;
            delete temp;
        }
    }
    void display(){
        Node *temp = head;
        cout<<"\nHEAD -> ";
        while(temp != NULL){
            cout<<temp->value<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL.\n";
    }
    void modify(int val, int n){
        if(head == NULL){
            cout<<"\nList is Empty\n";
            return;
        }
        Node* temp = head;
        if(n == 1){
            temp->value = val;
            return;
        }
        else{
            for(int i = 0; i < n - 1 &&  temp != NULL; i++){
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<"\nInvalid.";
                return;
            }
            else{
                temp->value = val;
            }
        }
    }
};



int main(){
    LinkedList ll;
    int choice;

    while (true) {
        cout << "\nLinked List Menu:\n";
        cout << "\t1. Insert at the beginning\n";
        cout << "\t2. Insert at the end\n";
        cout << "\t3. Insert at nth position\n";
        cout << "\t4. Delete at the beginning\n";
        cout << "\t5. Delete at the end\n";
        cout << "\t6. Delete by value\n";
        cout << "\t7. Modify value at nth position\n";
        cout << "\t8. Display linked list\n";
        cout << "\t9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int val1;
                cout << "Enter value to insert: ";
                cin >> val1;
                ll.insertAtStart(val1);
                break;

            case 2:
                int val2;
                cout << "Enter value to insert: ";
                cin >> val2;
                ll.insertAtEnd(val2);
                break;

            case 3:
                int val3, pos;
                cout << "Enter value to insert: ";
                cin >> val3;
                cout << "Enter position to insert: ";
                cin >> pos;
                ll.insertAtNthPosition(val3, pos);
                break;

            case 4:
                ll.deleteAtStart();
                break;

            case 5:
                ll.deleteAtEnd();
                break;

            case 6:
                int valToDelete;
                cout << "Enter value to delete: ";
                cin >> valToDelete;
                ll.deleteByVal(valToDelete);
                break;

            case 7:
                int newVal, position;
                cout << "Enter new value: ";
                cin >> newVal;
                cout << "Enter position to modify: ";
                cin >> position;
                ll.modify(newVal, position);
                break;

            case 8:
                ll.display();
                break;

            case 9:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}