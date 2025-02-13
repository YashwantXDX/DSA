#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

    Refer Video :- https://www.youtube.com/watch?v=pMHXL46exp4&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=112

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

bool searchData(Node *root, int key){

    if(!root)
        return false;
    
    if(root -> data == key)
        return true;
    
    if(root -> data > key)
        searchData(root -> left, key);
    
    else
        searchData(root -> right, key);

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

int main(){

    vector<int> arr = {82,1,106,58,89,56,68,92,24,35,26};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }

    cout << "Search 89 : " << searchData(root, 89);
    
}

