#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

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

int height(Node* node) {
    
    // The Question is asking to count the edges so return -1
    // If the question wants to count Nodes then return 0
    if(node == NULL)
        return -1;

    return 1 + max(height(node -> left), height(node -> right));

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int count = height(root);
    cout << count;

}

/*

            12
        8       18
    5       11

*/