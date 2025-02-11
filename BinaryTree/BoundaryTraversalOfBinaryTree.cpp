#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?page=1&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions

    Refer Video :- https://www.youtube.com/watch?v=aBqPnkXmvpY&t=3723

    Problem Logic:

    Make a ans vector

    Travers all the left part of the tree, only the left part and push the elements into ans.
    
    Now, Find the leaf elements and push them into ans.

    Now, traverse the right part of the tree, dont go left, only go when there is not other right but have left, and post order push the ans.

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

void leftSide(Node *root, vector<int> &ans){

    if(!root || (!root -> left && !root -> right)) return;

    ans.push_back(root -> data);

    // Agar Left Side hai
    if(root -> left)
        leftSide(root -> left, ans);
    
    // Agar Left Side nahi hai par uske niche elements hai
    else
        leftSide(root -> right, ans);

}

void leafSide(Node *root, vector<int> &ans){

    if(!root) return;

    if(!root -> left && !root -> right)
        ans.push_back(root -> data);


    // No Leaf?
    leafSide(root -> left, ans);
    leafSide(root -> right, ans);

}

void rightSide(Node *root, vector<int> &ans){

    if(!root || (!root -> left && !root -> right)) return;

    // Right Part me Jaooo
    if(root -> right)
        rightSide(root -> right, ans);
    
    // No Right Part?
    else
        rightSide(root -> left, ans);
    
    ans.push_back(root -> data);

}

vector<int> boundaryTraversal(Node *root){

    vector<int> ans;
    ans.push_back(root -> data);

    // Left Boundary Except Root and Leaf Node
    leftSide(root -> left, ans);

    // Leaf Node
    if(root -> left || root -> right)
        leafSide(root, ans);

    // Right Boundary in Reverse Except Root and Leaf Node
    rightSide(root -> right, ans);

    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = boundaryTraversal(root);

    for(int i : ans)
        cout << i << " ";
}