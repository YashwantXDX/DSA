#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions



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

int height(Node *root, bool &valid){

    if(root == NULL) return 0;
        
    // Find height of left and right of the current node
    int left = height(root -> left, valid);
    int right = height(root -> right, valid);
    
    // We used absolute because the answer can be negetive,
    // we removed -1 <= height <= 1 by this trick
    if(abs(left - right) > 1)
        valid = false;
    
    // return the current height
    return 1 + max(left, right);

}

bool isBalanced(Node* root) {
    
    bool valid = true;

    height(root, valid);

    return valid;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    bool balanced = isBalanced(root);
}