#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data, height;
    Node *left, *right;

    Node(int data){
        this -> data = data;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node *root){

    // No Root exist
    if(!root) return 0;

    // root exist
    return root -> height;

}

int getBalance(Node *root){

    return getHeight(root -> left) - getHeight(root -> right);

}

Node* rightRotation(Node *root){

    Node *child = root -> left;
    Node *childRight = child -> right;
    
    child -> right = root;
    root -> left = childRight;

    // Update Height of Root
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    // Update Height of Root
    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;
}

Node* leftRotation(Node *root){

    Node *child = root -> right;
    Node *childLeft = child -> left;

    child -> left = root;
    root -> right = childLeft;

    // Update Height of Root
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    // Update Height of Child
    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;
}

Node* insertToAVL(Node* root, int data)
{
    
    // If doesn't exist
    if(!root) return new Node(data);

    // If exist
    // Agar data root ke data se chota hai to left me daalo
    if(data < root -> data)
        root -> left = insertToAVL(root -> left, data);
    
    // Agar data root ke data se bda hai to right me daalo
    else if(data > root -> data)
        root -> right = insertToAVL(root -> right, data);
    
    // Vrna ek duplicate value aa gyi hai
    // to use ignore karo
    else
        return root;
    
    // Update Height
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    // Check Balancing
    int balance = getBalance(root);

    // Left Left Case
    // balance 1 se bda and data mere root -> left -> data se chota
    if(balance > 1 && data < root -> left -> data)
        return rightRotation(root);

    // Right Right Case
    // balance -1 se chota and data mere root -> right -> data se bada
    else if(balance < -1 && data > root -> right -> data)
        return leftRotation(root);

    // Left Right Case
    // balance 1 se bda and data mere root -> left -> data se bada
    else if(balance > 1 && data > root -> left -> data){
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    }

    // Right Left Case
    // balance -1 se chota and data mere root -> right -> data se chota
    else if(balance < -1 && data < root -> right -> data){
        root -> right = rightRotation(root -> right);
        return leftRotation(root);
    }

    // No Unbalance
    // jab -1 <= balance <= 1 ho
    else
        return root;
}

void printTree(Node *root){

    if(!root) return;

    printTree(root -> left);
    cout << root -> data << " ";
    printTree(root -> right);

}

int main(){
    
    // No Duplicates

    Node *root = NULL;

    root = insertToAVL(root, 10);
    root = insertToAVL(root, 20);
    root = insertToAVL(root, 80);
    root = insertToAVL(root, 60);
    root = insertToAVL(root, 30);
    root = insertToAVL(root, 40);
    root = insertToAVL(root, 50);

    printTree(root);

}