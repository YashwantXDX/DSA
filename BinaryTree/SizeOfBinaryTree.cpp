#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/size-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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

void getTheSizeDamnIt(Node* node, int &size){
        
    if(node == NULL)
        return;
        
    // Go Left
    getTheSizeDamnIt(node -> left, size);
    
    // Go Right
    getTheSizeDamnIt(node -> right, size);
    
    size++;
    
    return;
    
}

int getSize(Node* node) {
    
    int size = 0;
    getTheSizeDamnIt(node, size);
    
    return size;
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int size = getSize(root);
    cout << size;

}