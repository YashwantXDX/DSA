#include<bits/stdc++.h>
using namespace std;

/*

    Problem Statement :- https://www.geeksforgeeks.org/problems/avl-tree-deletion/1

    Refer Video :- https://www.youtube.com/watch?v=ytesTkCa3wk

    Problem Logic :-

    Find The data, if found then - 

    1. Leaf Node - Just return NULL and check balance of parent nodes.

    2. Single Child Exist
        i. Left Child - Delete that node and return its left and check balance of parent nodes.
        
        ii. Right Child - Delete that node and return its right and check balance of parent nodes.
    
    3. Both Child Exist 
        i. Go to leftmost element in the root -> right

        ii. update root -> data with that leftmost element

        iii. delete the root -> right

    4. Update Root's Height

    5. Check Balance, and If Unbalanced then Check which side is Unbalanced.

        i. Left Side (balance > 1)
            a. It is left left case when balance of root -> left comes >= 0

            b. It is Left Right case when balance of root -> left comes smaller

        ii. Right Side (balance < -1)
            a. It is Right Right case when balance of root -> right comes <= 0

            b. It is Right Left case when balance of root -> right comes bigger
    
    6. If Balanced, simply return root.
    
*/

class Node{
    public:
    int data, height;
    Node *left, *right;
    
    Node(int data){
        this -> data = data;
        height = 1;
        right = left = NULL;
    }
};

int getHeight(Node *root){
    if(!root) return 0;

    return root -> height;
}

int getBalance(Node *root){
    return getHeight(root -> left) - getHeight(root -> right);
}

Node *rightRotate(Node *root){

    Node *child = root -> left;
    Node *childRight = child -> right;

    child -> right = root;
    root -> left = childRight;

    // Update Height
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;
}

Node *leftRotate(Node *root){

    Node *child = root -> right;
    Node *childLeft = child -> left;

    child -> left = root;
    root -> right = childLeft;

    // Update Height
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;

}

Node* deleteNode(Node* root, int data)
{

    if(!root) return NULL;

    // Go Left Side
    if(data < root -> data)
        root -> left = deleteNode(root -> left, data);
    
    // Go Right Side
    else if(data > root -> data)
        root -> right = deleteNode(root -> right , data);
    
    // We got data to be deleted
    else{

        // Leaf Node
        if(!root -> right && !root -> left){
            delete root;
            return NULL;
        }

        // One Child Exist
        // Left Child Exist
        else if(!root -> right && root -> left){
            Node *temp = root -> left;
            delete root;
            return temp;
        }

        // Right Child Exist
        else if(root -> right && !root -> left){
            Node *temp = root -> right;
            delete root;
            return temp;
        }

        // Both Child Exist
        else{
            
            // Get the Root -> Right Side Smallest Element
            Node *curr = root -> right;
            while(curr -> left)
                curr = curr -> left;
            
            // update the root -> data with the Right Side Smallest Element
            root -> data = curr -> data;
            root -> right = deleteNode(root -> right, root -> data);

        }

    }

    // Update Height
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

    // Check Balance
    int balance = getBalance(root);

    // If Not Balance

    // Left Side
    if(balance > 1){

        // Left Left
        if(getBalance(root -> left) >= 0)
            return rightRotate(root);

        // Left Right
        else{
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }

    }
    // Right Side
    else if(balance < -1){

        // Right Right
        if(getBalance(root -> right) <= 0)
            return leftRotate(root);

        // Right Left
        else{
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }

    }

    // If Balance
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

    Node *root = new Node(4);
    root -> left = new Node(2);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right = new Node(6);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);
    Node *ans = deleteNode(root, 6);

    printTree(ans);

}