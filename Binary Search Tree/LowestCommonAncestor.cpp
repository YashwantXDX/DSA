#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

    Refer Video :- https://www.youtube.com/watch?v=YKo8QaW02z8

    Problem Logic :-

    If n1 and n2 chota hai root se to left jao, agar dono bade hai to right hai, vrna hume ancestor mil gya
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

Node *insertData(Node *root, int target){

    if(!root){
        return new Node(target);
    }

    if(root -> data > target){
        root -> left = insertData(root -> left, target);
    }

    else{
        root -> right = insertData(root -> right, target);
    }

    return root;
}

void printData(Node *root){

    while(root){

        if(!root -> left){
            cout << root -> data << " ";
            root = root -> right;
        }

        else{

            Node *curr = root -> left;

            while(curr -> right && curr -> right != root)
                curr = curr -> right;
            
            if(curr -> right == NULL){
                curr -> right = root;
                root = root -> left;
            }

            else{
                cout << root -> data << " ";
                root = root -> right;
                curr -> right = NULL;
            }

        }

    }

}

Node* LCA(Node* root, Node* n1, Node* n2) {
    
    if(!root) return NULL;

    if(root -> data > n1 -> data && root -> data > n2 -> data)
        return LCA(root -> left, n1, n2);
    
    else if(root -> data < n1 -> data && root -> data < n2 -> data)
        return LCA(root -> right, n1, n2);
    
    else
        return root;

}

int main(){

    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }

    Node *n1 = new Node(4);
    Node *n2 = new Node(10);
    Node *ans = LCA(root, n1, n2);

    cout << ans -> data << " ";
    
}

