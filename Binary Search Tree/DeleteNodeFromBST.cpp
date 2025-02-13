#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1

    Refer Video :- https://www.youtube.com/watch?v=pMHXL46exp4&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=112


    Pseude Code :- 

    1. If Leaf Node
        a) delete Node
        b) return NULL
    
    2. If only one child
        a) if only left child exist
            i) delete Node
            ii) return left -> child
        b) if only right child exist
            i) delete Node
            ii) return right -> child
    
    3. If both child exist and parent != root
        a) find the greatest element in left(child)
        b) parent ke right ko bolo ki child ke left ko point kre
        c) child -> left = root -> left
        d) child -> right = root -> right
        e) delete root
        f) return child
    
    4. Agar Parent == Root hai
        a) find the greatest element in left(child)
        b) child -> right = root -> right
        c) delete root
        d) return child
        
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

Node *deleteNode(Node *root, int key){

    if(!root)
        return NULL;
    
    if(root -> data > key){
        root -> left = deleteNode(root -> left, key);
        return root;
    }

    if(root -> data < key){
        root -> right = deleteNode(root -> right, key);
        return root;
    }
    
    else{
        // Leaf Node Delete
        if(!root -> left && !root -> right){
            delete root;
            return NULL;
        }

        // 1 child exist

        // if left part exist
        else if(!root -> right){
            Node *temp = root -> left;
            delete root;
            return temp;
        }

        // if right part exist
        else if(!root -> left){
            Node *temp = root -> right;
            delete root;
            return temp;
        }

        // Both child Exist
        else{

            // find the greatest element from left
            Node *child = root -> left;
            Node *parent = root;

            while(child -> right){
                parent = child;
                child = child -> right;
            }

            // root != parent
            if(root != parent){

                parent -> right = child -> left;
                child -> left = root -> left;
                child -> right = root -> right;
                delete root;
                
                return child;
            }

            // root == parent
            else{
                
                child -> right = root -> right;
                delete root;
                return child;

            }
        }
    }
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

    cout << "Before Deletion : ";
    printData(root);

    cout << "\n\nAfter Deletion : ";
    deleteNode(root , 1);
    printData(root);
    
}

