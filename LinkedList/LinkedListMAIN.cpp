#include <iostream>
using namespace std;

//making a node structure containing int data and pointer to next node
struct Node{
    int value;
    struct Node *next;
    //parameterized constructor with default argument
    Node(int val = 0) :value(val), next(NULL){};
    //parameterized constructor
    Node(int val, Node *tempNext): value(val), next(tempNext){};
};

class LinkedList{
    //head pointer
    Node *head;
    public:
        //default constructor, initializing head pointer
        LinkedList():head(NULL){};

        //inserting elements at start of list
        void insertAtStart(int val){
            //make a new node
            Node *newNode = new Node(val);
            //if list is empty, make the new node the head
            if(head == NULL){
                head = newNode;
                return;
            }
            //else, make the new node the head, while making the new node's next the previous head
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        void insertAtEnd(int val){
            //make a new node
            Node* newNode = new Node(val);
            //if list is empty, make new node the head
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                Node* temp = head; //temporary variable for iteration
                while(temp->next != NULL){ //iterate till temp reaches last Node
                    temp = temp->next;
                }
                temp->next = newNode; //assign last Nodes next to newNode
                //newNode's next is already NULL
            }
        }
        
        void insertAtNthPosition(int val, int n = 1){ // n = 1 as default argument
            Node *newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            if(n == 1){ //if position is at the beginning
                insertAtStart(val);
                return;
            }
            Node* temp = head; //node for traversal
            --n; // to add element at position 4, temp has to go to 3
            for(int i = 0; i < n - 1 && temp!= NULL; i++){
                temp = temp->next;
            }
            if(temp == NULL){ // n exceedes max size
                cout<<"\nInvalid Position\n";
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteAtStart(){
            Node* temp;
            if(head == NULL){
                cout<<"\nList is empty.\n";
                return;
            }
            else{
                temp = head;
                head = temp->next;
                delete temp;
                //or head = head->next;
                cout<<"\nDeleted.\n";
            }
        }
        void deleteAtEnd(){
            Node *temp, *prev; // 2 pointers to keep track of nodes
            if(head == NULL){
                cout<<"\nList is Empty.\n";
                return;
            }
            else{
                temp = prev = head; //initialize both to head
                while(temp->next != NULL){ //traverse till end of list
                    prev = temp; 
                    temp = temp->next;
                }
                //temp will be the last node, which is to be deleted
                //prev is the node before temp
                prev->next = NULL;
                delete temp;
                cout<<"\nDeleted.\n";
            }
        }

        void deleteByVal(int val){
            Node* temp = head;
            //if head is to be deleted
            if(temp!= NULL && temp->value == val){
                head = temp->next;
                delete temp;
                return;
            }
            //else LOOP over list to delete element
            else{
                Node* current = head;
                while(temp != NULL && temp->value != val){
                    //when node is found, delete the node and modify pointers
                    current = temp;
                    temp = temp->next;
                }
                if(temp == NULL){
                    cout<<"\nValue not found.\n";
                    return;
                }
                current->next = temp->next;
                delete temp;
            }
        }

        int length(){
            Node *temp = head; //pointer for traversal
            int count = 0; //counter for counting
            while(temp != NULL){ //loop till end reaches
                temp = temp->next;
                count++;
            }
            //delete temp; 
            // no need to delete temp as it is a traversal pointer 
            //deleting pointers that are NULL and used in pointers can bring errors
            return count;
        }
        

        void modify(int val, int n){
            Node* temp = head;
            --n;
            for(int i = 0; i < n  && temp != NULL; i++){
                temp = temp->next;
            }
            temp->value = val;
        }
        //LOOP OVER THE LIST, RETURN TRUE IF FOUND
        int search(int val){
            Node* temp = head;
            while (temp != NULL){
                if(temp->value == val){
                    return 1;
                }
                temp = temp->next;
            }
            return 0;
        }

        

        void display(){
            cout<<endl;
            Node* temp = head; //initialize traversal element temp to head
            cout<<"HEAD -> ";
            while(temp!= NULL){ //traverse till temp reaches end i.e. NULL
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL."<<endl;
            
        }
};

int main() {
    LinkedList ll;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Nth Position\n";
        cout << "4. Delete at Start\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete by Value\n";
        cout << "7. Display\n";
        cout << "8. Length of List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the start: ";
                cin >> value;
                ll.insertAtStart(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                ll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                ll.insertAtNthPosition(value, position);
                break;
            case 4:
                ll.deleteAtStart();
                break;
            case 5:
                ll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                ll.deleteByVal(value);
                break;
            case 7:
                ll.display();
                break;
            case 8:
                cout << "Length of the list is: " << ll.length() << endl;
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
