#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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

void getTheSumDamnIt(Node *root, int &sum){
        
    if(root == NULL) return;

    // Go Left
    getTheSumDamnIt(root -> left, sum);
    
    // Go Right
    getTheSumDamnIt(root -> right, sum);
    
    sum += root -> data;
    
    return;
    
}

int sumBT(Node* root) {
    int sum = 0;
    getTheSumDamnIt(root, sum);
    
    return sum;
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int sum = sumBT(root);
    cout << sum;

}