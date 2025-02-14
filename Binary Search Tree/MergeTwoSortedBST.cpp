#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

    Refer Video :- https://www.youtube.com/watch?v=GMZ3DcXiHHQ&t=1509

    Store inorder traversed elements in array of both roots.

    then just merge two sorted array.

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

// Morris Traversal Inorder
void makeBSTintoArray(Node *root, vector<int> &arr){
        
    while(root){
        
        if(!root -> left){
            arr.push_back(root -> data);
            root = root -> right;
        }
        
        else{
            
            Node *temp = root -> left;
            
            while(temp -> right && temp -> right != root)
                temp = temp -> right;
            
            if(!temp -> right){
                temp -> right = root;
                root = root -> left;
            }
            
            else{
                temp -> right = NULL;
                arr.push_back(root -> data);
                root = root -> right;
            }
            
        }
        
    }
    
}   

// Merge both arrays
vector<int> mergeIt(vector<int> &arr1, vector<int> &arr2){
    
    int ptr1 = 0, ptr2 = 0;
    vector<int> merged;
    
    while(ptr1 < arr1.size() && ptr2 < arr2.size()){
        
        if(arr1[ptr1] <= arr2[ptr2]){
            merged.push_back(arr1[ptr1]);
            ptr1++;
        }
        
        else{
            merged.push_back(arr2[ptr2]);
            ptr2++;
        }
        
    }
    
    while(ptr1 < arr1.size()){
        merged.push_back(arr1[ptr1]);
        ptr1++;
    }
    
    while(ptr2 < arr2.size()){
        merged.push_back(arr2[ptr2]);
        ptr2++;
    }
    
    return merged;
    
}

vector<int> merge(Node *root1, Node *root2) {
        
    vector<int> root1Arr, root2Arr;
    
    // Make both BST into vector array
    makeBSTintoArray(root1, root1Arr);
    makeBSTintoArray(root2, root2Arr);
    
    // merge both the array
    vector<int> mergedArray = mergeIt(root1Arr, root2Arr);
    
    return mergedArray;
    
}

int main(){

    vector<int> arr = {1,0,48,12,49};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }
    
}

