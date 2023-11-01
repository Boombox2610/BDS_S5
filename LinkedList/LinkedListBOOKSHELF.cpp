#include <iostream>
#include <string>
using namespace std;
/*You are tested with creating a program to manage a digital bookshelf. Each book on the shelf has a title, author, and publication year. Implement this bookshelf using a singly linked list. WAP that allows user to add new books, remove books by title, display the bookshelf, and find books by a specific order.*/
struct Bookshelf{
    string title;
    string author;
    int publicationYear;
    Bookshelf(string tit, string auth, int year):title(tit), author(auth), publicationYear(year){};
};
struct Node{
    Bookshelf shelf;
    Node *next;
    Node(Bookshelf book):shelf(book){};
};
class LinkedList{
    Node *head;
    public:
    LinkedList():head(NULL){};
    void insertAtNthPos(int pos);
    void removeByTitle(string title);
    void display();
    void findBook(string);
};
void LinkedList::insertAtNthPos(int pos = 1){
    string title, author;
    int year;
    cin.ignore();
    cout<<"\nEnter Title of Book: ";
    getline(cin, title);
    cout<<"\nEnter Author of book: ";
    getline(cin, author);
    cout<<"\nEnter Publication Year: ";
    cin>>year;
    Node *newNode = new Node(Bookshelf(title, author, year));
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
        return;
    }
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    for(int i = 0; i < pos-2 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\nNot found.";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::removeByTitle(string title){
    Node *temp = head;
    if(temp->next == NULL && temp->shelf.title == title){
        head = temp->next;
        head = temp;
    }
    Node *cur = head;
    while(temp->shelf.title != title && temp != NULL){
        cur = temp; 
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\nNot found.";
        return;
    }
    cur->next = temp->next;
    delete temp;
}

void LinkedList::display(){
    if (head == NULL) {
        cout << "\nBookshelf is empty.";
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout<<"\nTitle: "<<temp->shelf.title;
        cout<<"\nAutor: "<<temp->shelf.author;
        cout<<"\nPublication Year: "<<temp->shelf.publicationYear;
        temp = temp->next;
    }
    cout<<endl<<endl;
}

void LinkedList::findBook(string tit){
    Node *temp = head;
    if(temp == NULL){
        cout<<"\nEmpty";
        return;
    }
    while(temp->shelf.title != tit && temp != NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\nNot found.";
        return;
    }
    cout<<"\nBOOK FOUND! --------->\n";
    cout<<"\nTitle: "<<temp->shelf.title;
    cout<<"\nAutor: "<<temp->shelf.author;
    cout<<"\nPublication Year: "<<temp->shelf.publicationYear;
    
}

int main() {
    LinkedList books;
    int choice;
    string title;

    do {
        cout << "\nMenu:";
        cout << "\n1. Add a book";
        cout << "\n2. Remove a book by title";
        cout << "\n3. Display the bookshelf";
        cout << "\n4. Find a book by title";
        cout << "\n5. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                books.insertAtNthPos();
                break;

            case 2:
                cin.ignore();
                cout << "Enter the title of the book to remove: ";
                getline(cin, title);
                books.removeByTitle(title);
                break;

            case 3:
                books.display();
                break;

            case 4:
                cin.ignore();
                cout << "Enter the title of the book to find: ";
                getline(cin, title);
                books.findBook(title);
                break;

            case 5:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
