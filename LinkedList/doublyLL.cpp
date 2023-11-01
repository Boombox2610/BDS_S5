#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int val = 0) : value(val), next(NULL), prev(NULL) {};
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {};

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtNthPosition(int val, int n) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }
        if (n == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            --n;
            for (int i = 0; i < n - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "INVALID";
                return;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != NULL) {
                newNode->next->prev = newNode;
            }
        }
    }

    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }

    void deleteByVal(int val) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->value != val) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value Not Found" << endl;
            return;
        }
        if (temp == head) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
        }
        delete temp;
    }

    void modify(int val, int n) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        if (n == 1) {
            temp->value = val;
        } else {
            for (int i = 0; i < n - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Invalid." << endl;
                return;
            } else {
                temp->value = val;
            }
        }
    }

    void display() {
        Node* temp = head;
        cout << "NULL <- ";
        while (temp != NULL) {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int choice;

    while (true) {
        cout << "\nDoubly Linked List Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at nth position" << endl;
        cout << "4. Delete at the beginning" << endl;
        cout << "5. Delete at the end" << endl;
        cout << "6. Delete by value" << endl;
        cout << "7. Modify value at nth position" << endl;
        cout << "8. Display linked list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int val1;
                cout << "Enter value to insert: ";
                cin >> val1;
                dll.insertAtStart(val1);
                break;

            case 2:
                int val2;
                cout << "Enter value to insert: ";
                cin >> val2;
                dll.insertAtEnd(val2);
                break;

            case 3:
                int val3, pos;
                cout << "Enter value to insert: ";
                cin >> val3;
                cout << "Enter position to insert: ";
                cin >> pos;
                dll.insertAtNthPosition(val3, pos);
                break;

            case 4:
                dll.deleteAtStart();
                break;

            case 5:
                dll.deleteAtEnd();
                break;

            case 6:
                int valToDelete;
                cout << "Enter value to delete: ";
                cin >> valToDelete;
                dll.deleteByVal(valToDelete);
                break;

            case 7:
                int newVal, position;
                cout << "Enter new value: ";
                cin >> newVal;
                cout << "Enter position to modify: ";
                cin >> position;
                dll.modify(newVal, position);
                break;

            case 8:
                dll.display();
                break;

            case 9:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}
