#include<bits/stdc++.h>
using namespace std;

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

void preOrder(Node *ptr){

    if(ptr == NULL)
        return;
    
    // Print Value
    cout << ptr -> data << " ";

    // Go Left
    preOrder(ptr -> left);

    // Go Right
    preOrder(ptr -> right);

    return;


}

void inOrder(Node *ptr){

    if(ptr == NULL) return;

    // Go to Left
    inOrder(ptr -> left);

    // Print Element
    cout << ptr -> data << " ";

    // Go to Right
    inOrder(ptr -> right);

    return;

}

void postOrder(Node *ptr){

    if(ptr == NULL) return;

    // Go to Left
    postOrder(ptr -> left);

    // Go to Right
    postOrder(ptr -> right);

    // Print Element
    cout << ptr -> data << " ";

    return;

}

int main(){
    cout << "Enter the Root Node : ";
    Node *tree = binaryTree();

    postOrder(tree);

}