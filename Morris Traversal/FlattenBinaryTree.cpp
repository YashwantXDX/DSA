#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
    
    Refer Video :- https://www.youtube.com/watch?v=TvfGWVAv_cc&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=110&t=3067

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

void flatten(Node *root)
    {
        while(root){
            
            // If Root ka Left Doesn't Exist
            if(!root -> left)
                root = root -> right;
            
            // If Exist
            else{
                
                Node *curr = root -> left;
                
                // Curr ko rightmost element pe le jao
                while(curr -> right)
                    curr = curr -> right;
                
                // curr ke right ko root ke right me point krvao
                curr -> right = root -> right;
                
                // root ke right ko root ke left me point krvao
                root -> right = root -> left;
                
                // root ke left ko NULL me point krvao
                root -> left = NULL;
                
                // root ko root ke right me point krvao
                root = root -> right;
                
            }
            
        }
    }

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    flatten(root);

    while(root){
        cout << root -> data << " ";
        root = root -> right;
    }
}