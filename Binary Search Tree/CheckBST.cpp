#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/check-for-bst/1

    Refer Video :- https://www.youtube.com/watch?v=Rq1II71_Glw

*/
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

bool checkBST(Node *root, int &prev){
        
    // root exist nhi krta to mai keh sktahu ki vo BST hai
    if(!root)
        return true;
        
    bool left = checkBST(root -> left, prev);
    
    // agar left se false aata hai mtlb BST nhi hai
    if(!left)
        return false;
    
    // agar root ka data prev ke data se less than ya equal hai
    // to vo BST nhi hai
    if(root -> data <= prev)
        return false;
    
    // prev ko update karo taki vo root ke prev ki
    // value ko hold kr ke rkhe
    prev = root -> data;
    
    // right ke liye search kro 
    return checkBST(root-> right, prev);
    
}

bool isBST(Node* root) {
    int prev = INT_MIN;
    return checkBST(root, prev);
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    cout << "binary Search Tree ? : " << isBST(root);

}

