#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/bst-to-max-heap/1

    Refer Video :- https://www.youtube.com/watch?v=ANjoYpXpDaw&t=2100s

    Problem Logic :-

    1. Inorder Travrse using Morris Traversal
    
    2. Replace the values of BST using PostOrder Traversal of InOrder Traversed Array using Morris Traversal.

*/

class Node{
    public:
    int data; Node *left, *right;
    Node(int data){this -> data = data; left = right = NULL;}
};

vector<int> inorder(Node *root){
        
    vector<int> ans;
    
    while(root){
        
        // If left Part Doesn't exist
        if(!root -> left){
            ans.push_back(root -> data);
            root = root -> right;
        }
        
        // Left Part Exist
        else{
            
            Node *curr = root -> left;
            
            while(curr -> right && curr -> right != root)
                curr = curr -> right;
            
            // If Left part not traversed
            if(curr -> right == NULL){
                curr -> right = root;
                root = root -> left;
            }
            
            // If left part is traversed
            else{
                curr -> right = NULL;
                ans.push_back(root -> data);
                root = root -> right;
            }
            
            
        }
        
    }
    
    return ans;
    
}

void fillValues(Node *root, vector<int> inOrder, int index){
    
    while(root){
        
        // If right Part Doesn't exist
        if(!root -> right){
            root -> data = inOrder[index--];
            root = root -> left;
        }
        
        // Right Part Exist
        else{
            
            Node *curr = root -> right;
            
            while(curr -> left && curr -> left != root)
                curr = curr -> left;
            
            // If Right part not traversed
            if(curr -> left == NULL){
                curr -> left = root;
                root -> data = inOrder[index--];
                root = root -> right;
            }
            
            // If Right part is traversed
            else{
                curr -> left = NULL;
                root = root -> left;
            }
            
            
        }
        
    }
    
}

void convertToMaxHeapUtil(Node* root)
{
    // Inorder Traversal of the tree    
    vector<int> inOrder = inorder(root);
    int size = inOrder.size();
    
    // Now fill the values in Post Order
    fillValues(root, inOrder, size - 1);
} 