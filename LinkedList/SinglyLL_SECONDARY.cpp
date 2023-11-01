//Dynamic data structure- size can be changed at run type
//Ease of insertion/deletion- no shifting required, only address updated
//Efficient Memory Utilization- size increases or derceases as per requirement
//implementation- advance data structures can be used using linked list
#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
};
Node *create(Node *h){
    int node, value, len;
    cout<<"Enter number of nodes: ";
    cin>>len;
    for(int i = 0; i < len; i++){
        Node* newNode = new Node;
        cout<<"Enter value: ";
        cin>>value;
        newNode ->value = value;
        newNode ->next = h;
        h = newNode;
    }
    return h;
}

Node *insertBeginning(Node *h){
    Node *newNode = new Node;
    int val;
    cout<<"Enter value to be inserted: ";
    cin>>val;
    newNode->value = val;
    newNode->next = h;
    h = newNode;
    return h; 
}
Node *insertAtEnding(Node* h){
    Node* newNode = new Node;
    int val;
    cout<<"Enter value to be inserted: ";
    cin>>val;
    newNode->value = val;
    Node* current = h;
    newNode->next = NULL;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return h;
}

Node *deleteAtBeginning(Node* h){
    Node* temp = h;
    h = h->next;
    delete temp;
    return h;
}

void search(Node* h){
    Node* current = h;
    int val;
    cout<<"Enter value to be searched: ";
    cin>>val;
    int counter = 0;
    while (current != NULL){
        if(current->value == val){
            counter++;
            break;
        }
        else{
            current = current->next;
        }
    }
    if(counter==0){
        cout<<"Value not found";
    }
    else{
        cout<<"Value present in the linked list.";
    }
}
void numOfNodes(Node* h){
    Node* current = h;
    int counter = 0;
    while(current!= NULL){
        counter++;
        current = current->next;
    }
    cout<<"Number of nodes: "<<counter;
}
void display(Node* h){
    Node* current = h;
    while(current != NULL){
        cout<<current->value<<" ";
        current = current->next;
    }
}

int main(){
    Node* head = NULL;
    head = create(head);
    head = insertAtEnding(head);
    head = insertAtEnding(head);
    head = deleteAtBeginning(head);
    search(head);
    numOfNodes(head);
    display(head);
    return 0;
}
