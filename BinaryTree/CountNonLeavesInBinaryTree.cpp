#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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

void countTheNonLeafDumbAss(Node *root, int &count){
        
    if(root == NULL)
        return;
    
    if(root -> left || root -> right)
        count++;    
    
    // Go Left
    countTheNonLeafDumbAss(root -> left, count);
    
    //Go Right
    countTheNonLeafDumbAss(root -> right, count);
    
    return;
    
}

int countNonLeafNodes(Node* root) {
    
    int count = 0;
    countTheNonLeafDumbAss(root, count);
    
    return count;
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int count = countNonLeafNodes(root);
    cout << count;

}