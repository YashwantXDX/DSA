#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/mirror-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    Just Swap the nodes and go on till it goes null


*/

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int data){
            this -> data = data;
            left = right = NULL;
        }
};

Node *binaryTree(){

    int x; cin >> x;

    if(x == -1) return NULL;

    Node *temp = new Node(x);

    // Left Side
    cout << "Enter Left Side of " << x << " : ";
    temp -> left = binaryTree();

    // Right Side
    cout << "Enter Right Side of " << x << " : ";
    temp -> right = binaryTree();

    return temp;
}

void mirror(Node* node) {
    
    if(node == NULL) return;

    Node *temp = node -> left;
    node -> left = node -> right;
    node -> right = temp;

    mirror(node -> left);
    mirror(node -> right);

    return;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    mirror(root);
}