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
    Node* head;
    public:
        //default constructor, initializing head pointer
        LinkedList():head(NULL){};

        //inserting elements at start of list
        void insert(int val){
            //make a new node
            Node* newNode = new Node(val);
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
        void createList(int n){
            //creates 'n' number of nodes
            for(int i = 0; i < n; i++){ // runs a loop that will add 'n' number of nodes
                int inp;
                cout<<"\nEnter a number to be put on index "<<i<<": ";
                cin>>inp;
                //calling insert function mentioned above
                insert(inp);
            }
        }
        int length(){
            Node *temp = head;
            int count = 0;
            while(temp != NULL){
                temp = temp->next;
                count++;
            }
            //delete temp;
            //delete temp not necessary as one should use delete only when memory was alocated with 'new' 
            //here, temp is only used as a pointer for traversal, and not alocated with 'new'
            //deleting temp is essentially trying to delete a null pointer, which is undefined behaviour in C++
            return count;
        }
        void insertAtNthPosition(int val, int n = 1){
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
            Node* temp = head;
            --n;
            for(int i = 0; i < n - 1 && temp!= NULL; i++){
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<"\nInvalid Position\n";
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
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

        void remove(int val){
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
                if(!temp){
                    cout<<"\nValue not found.\n";
                    return;
                }
                current->next = temp->next;
                delete temp;
            }
        }
        void display(){
            cout<<endl;
            Node* temp = head;
            cout<<"NULL <-";
            while(temp!= NULL){
                cout<<temp->value<<" <- ";
                temp = temp->next;
            }
            cout<<"Head."<<endl;
            
        }

        void ultaDisplay(){
            cout<<endl;
            Node* temp = NULL;
            while(temp != head){
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
        }
};

int main(){
    LinkedList ll;
    ll.insert(6);
    ll.insert(9);
    ll.insert(4);
    ll.insert(8);
    cout<<"Current linked List: \n";
    cout<<"\nLength is: "<<ll.length();
    ll.display();
    ll.remove(4);
    cout<<"After deleting 4 linked List: \n";
    cout<<"\nLength is: "<<ll.length();
    ll.display();
    ll.insertAtNthPosition(69);
    ll.insertAtNthPosition(96, 3);
    ll.display();
    cout<<endl<<ll.search(11);
    cout<<endl;
    ll.modify(80, 4);
    ll.display();
    ll.ultaDisplay();
    return 0;
}
