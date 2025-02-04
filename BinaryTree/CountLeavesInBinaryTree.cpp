#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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

void count(Node *root, int &num){
        
    if(root == NULL) return;
    
    count(root -> left, num);
    count(root -> right, num);
    
    if(root -> left == NULL && root -> right == NULL)
        num++;
    
    return;
    
}

int countLeaves(Node* root) {
    int num = 0;
    count(root, num);
    
    return num;
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int count = count(root);
    cout << count;

}