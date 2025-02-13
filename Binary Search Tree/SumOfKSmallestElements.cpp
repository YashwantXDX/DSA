#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

    Refer Video :- https://www.youtube.com/watch?v=Rq1II71_Glw

    Problem Logic :-

    Just InOrder Traverse and add to sum till k != 0,
    if k == 0 then just return.

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

void findSum(Node *root, int &k, int &add){

    if(!root) return;

    findSum(root -> left, k, add);

    if(k == 0) return;

    add += root -> data;
    k -= 1;
    
    findSum(root -> right, k, add);

}

int sum(Node *root, int k){

    int add = 0;

    findSum(root, k, add);
    
    return add;

}

int main(){

    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }

    int k = 3;

    cout << "Kth Smallest Element is : " << sum(root, k);
    
}

