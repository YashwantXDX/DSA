#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions


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

bool isIdentical(Node *r1, Node *r2) {
    
    // Base Condition Where both nodes are NULL means the passed all the obstacles
    if(r1 == NULL && r2 == NULL)
        return 1;
    
    // Check The conditions where one node goes null and other doesn't
    // Also check where the one nodes data is equal or not to other nodes data
    // If equal then dont do anything but if it doeesnt then return 0
    if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL) ||(r1 -> data != r2 -> data)){
     
        return 0;

    }
    
    // Check for left and Right side of the tree
    return isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right);

}

int main(){

    cout << "Enter Root Node : ";
    Node *root1 = binaryTree();
    Node *root2 = binaryTree();
    
    cout << "Are They Identical ? " << isIdentical(root1, root2) ? "Yes The Are" : "No They Are Not";
    

}