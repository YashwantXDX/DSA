#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

    Refer Video :- https://www.youtube.com/watch?v=YKo8QaW02z8

    Problem Logic :-

    If n1 and n2 chota hai root se to left jao, agar dono bade hai to right hai, vrna hume ancestor mil gya uske baad ancestor ko root node maan ke uspe inorder traverse kar do.
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

void find(Node *root, int &low, int &high, vector<int> &ans){
        
    if(!root) return;
    
    if(root -> data > low && root -> data > high)
        find(root -> left, low, high, ans);
    
    else if(root -> data < low && root -> data < high)
        find(root -> right, low, high, ans);
    
    else{
        
        find(root -> left, low, high, ans);
        
        ans.push_back(root -> data);
        
        find(root -> right, low, high, ans);
        
    }
    
}

vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int> ans;
    
    find(root, low, high, ans);
    
    return ans;
}

int main(){

    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }
    
}

