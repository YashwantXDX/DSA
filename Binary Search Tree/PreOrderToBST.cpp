#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

    Refer Video :- https://www.youtube.com/watch?v=Ir9Ni46g8Qo

    Just keep track of the Range.

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

Node * BST(vector<int> &arr, int &index, int lower, int upper){

    if(index == arr.size() || lower > arr[index] || arr[index] > upper)
        return NULL;
    
    Node *root = new Node(arr[index++]);

    root -> left = BST(arr, index, lower, root -> data);

    root -> right = BST(arr, index, root -> data, upper);

    return root;

}

Node *BSTfromPreOrder(vector<int> &arr){

    int index = 0;
    return BST(arr, index, INT_MIN, INT_MAX);

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

    vector<int> arr = {8,5,1,7,10,12};
    Node *root = BSTfromPreOrder(arr);

    printData(root);
    
}

