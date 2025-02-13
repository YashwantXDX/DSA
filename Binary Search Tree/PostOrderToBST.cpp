#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1

    Refer Video :- https://www.youtube.com/watch?v=Ir9Ni46g8Qo

    Just keep track of the Range but from right to left.

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

Node *BST(int *post, int &size, int &index, int lower, int upper){
    
    if(index == -1 || post[index] < lower || post[index] > upper)
        return NULL;
    
    Node *root = new Node(post[index--]);
    
    root -> right = BST(post, size, index, root -> data, upper);
    
    root -> left = BST(post, size, index, lower, root -> data);
    
    return root;
    
}

Node *constructTree (int post[], int size)
{
    int index = size - 1;
    
    return BST(post, size, index, INT_MIN, INT_MAX);
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

    int arr[] = {1,7,5,50,40,10};
    Node *root = constructTree(arr, 6);

    printData(root);
    
}

