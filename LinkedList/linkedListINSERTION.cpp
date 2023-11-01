#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
};


//INSERTION
void insertAtBeginning(Node** head, int val){
    //dynamically create memory for new node
    Node* newNode = new Node();
    newNode-> value = val;
    newNode->next = *head;
    *head = newNode;
    cout<<"\nNew Node: "<<newNode->value<<" inserted.\n";
}
void insertAtEnding(Node**head, int val){
    Node* newNode = new Node();
    newNode->value = val;
    //Last node always points to NULL
    newNode->next = NULL;
    //if linked list was empty
    if(*head == NULL){
        *head = newNode;
        cout<<endl<<newNode->value<<" inserted.\n";
        return;
    }
    Node* tempNode = *head;
    //Reach last element of list
    while(tempNode->next!=NULL){
        tempNode = tempNode->next;
    }
    //assign last nodes next to this newNode
    tempNode->next = newNode;
    cout<<newNode->value<<" inserted.";
}
//getCurrSize REQUIRED for insertAfterNthNode
int getCurrSize(Node* node){
    int size = 0;
    while(node!= NULL){
        node = node->next;
        size++;
    }
    return size;
}
void insertAfterNthNode(int n, int val, Node** head){
    int size = getCurrSize(*head);
    //negative position insertions not possible
    //cant insert if position to insert is greater than size of linked list
    if(n < 0 || n > size){
        cout<<"\nInvalid Position\n";
    }
    if(n == 0){
        insertAtBeginning(head, val);
    }
    else{
        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = NULL;
        //temp node used to travel linked list
        Node* tempNode = *head;
        //traverse till the nth node
        while(--n){
            tempNode = tempNode->next;

        }
        //Assign newNode's next to nth node's next
        newNode->next = tempNode->next;
        //assign nth node's next to this new node
        tempNode->next = newNode;
        //new Node inserted
        cout<<endl<<newNode->value<<" inserted.\n";
    }
}

//DELETION

void display(Node* node){
    cout<<endl;
    //as linked list will end when node is NULL
    while(node != NULL){
        cout<<node->value<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 14);
    insertAtBeginning(&head, 16);
    display(head);
    insertAtEnding(&head, 50);
    insertAtEnding(&head, 60);
    insertAtEnding(&head, 70);
    insertAtEnding(&head, 80);
    display(head);
    //insert data 18 after 5th node
    insertAfterNthNode(3, 18, &head);
    display(head);
    return 0;
}