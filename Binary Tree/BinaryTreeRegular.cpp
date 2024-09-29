#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* Insert(Node* root, int val) {
    if (root == nullptr) {
        Node* newNode = new Node(val);
        root = newNode;
    } else if (val <= root->data) {
        root->left = Insert(root->left, val);
    } else {
        root->right = Insert(root->right, val);
    }
    return root;
}

Node* Delete(Node* root, int val) {
    if (root == nullptr) {
        cout << "\nEmpty Tree..." << endl;
        return root;
    } else if (val < root->data) {
        root->left = Delete(root->left, val);
    } else if (val > root->data) {
        root->right = Delete(root->right, val);
    } else { // root->data == val
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

bool searchTree(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    else if (val <= root->data) return searchTree(root->left, val);
    else return searchTree(root->right, val);
}

void inOrderTraverse(Node* root) {
    if (root == nullptr) return;
    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
}

void preOrderTraverse(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void postOrderTraverse(Node* root) {
    if (root == nullptr) return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    cout << "\nPre order (root -> left -> right): ";
    preOrderTraverse(root);
    cout << "\nIn order (left -> root -> right): ";
    inOrderTraverse(root);
    cout << "\nPost order (left -> right -> root): ";
    postOrderTraverse(root);

    // Searching
    int val;
    cout << "\nEnter a number to be searched: ";
    cin >> val;
    cout << (searchTree(root, val) ? "Found" : "Not Found");

    //Deleting
    cout << "\nDeleting searched Value: ";
    root = Delete(root, val);
    cout << "\nPre order (root -> left -> right): ";
    preOrderTraverse(root);
    cout << "\nIn order (left -> root -> right): ";
    inOrderTraverse(root);
    cout << "\nPost order (left -> right -> root): ";
    postOrderTraverse(root);
    return 0;
}
