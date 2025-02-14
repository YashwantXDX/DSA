#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

    Refer Video :- https://www.youtube.com/watch?v=Ir9Ni46g8Qo&t=3913

    Very Important Problem, this is same as build BST with Preorder Traversal. 

    Range Method.

    Recursion Method has probability of failing some testcase where elements can be hundred thousands or more.

    If encountered this, then Follow Iterative Approach to solve that problems.

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

// Recursive Approach (can be failed when arr elements are more than 1 Lakh)
void canBeBSTRecursive(int *arr, int &size, int &index, int lower, int upper){

    if(index == size || lower < arr[index] || arr[index] > upper)
        return;
    
    int val = arr[index++];

    canBeBSTRecursive(arr, size, index, lower, val);

    canBeBSTRecursive(arr, size, index, val, upper);

}


int canRepresentBSTRecursive(int *arr, int size){

    int index = 0;

    // Recursive Approach
    canBeBSTRecursive(arr, size, index, INT_MIN, INT_MAX);

    return index == size;

}

int canRepresentBST(int *arr, int size){

    stack<int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int left, right;

    // BST ban ne ke liye element ko lower < element < upper ke bich me rhna pdega
    for(int i = 0; i < size; i++){

        // Agar lower ka top bda ho gya element se
        // mtlb vo BST nhi ban skta
        if(lower.top() > arr[i]) return 0;
        
        // Agar element ki value upper ke top se badi aati hai mtlb vo range me nhi hai orr lower and upper ko pop tb tk krna hai jb tk range me nhi aa jata
        while(upper.top() < arr[i]){
            lower.pop();
            upper.pop();
        }

        // Agar element range me hai to uske left and right ke liye chlana pdega
        left = lower.top();
        right = upper.top();
        lower.pop();
        upper.pop();

        // ab stack me elements daalo
        // First Right
        lower.push(arr[i]);
        upper.push(right);

        // Ab Left ke liye
        lower.push(left);
        upper.push(arr[i]);

    }

    // Agar Valid hai
    return 1;

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

    int arr[] = {2,4,3};
    int size = 3;

    cout << canRepresentBST(arr, size);
    
}

