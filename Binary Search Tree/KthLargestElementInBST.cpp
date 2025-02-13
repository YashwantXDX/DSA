#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

    Refer Video :- https://www.youtube.com/watch?v=Rq1II71_Glw

    Problem Logic :-

    Just InOrder Traverse from right side and update the answer as the k decreases till k = 0

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

void find(Node *root, int &k, int &element){

    if(!root) return;

    find(root -> right, k, element);

    if(k == 0) return;

    element = root -> data;

    k -= 1;

    find(root -> left, k, element);

}

int kthLargest(Node *root, int k){

    if(!root -> left && !root -> right)
        return -1;

    int element = -1;

    find(root, k, element);

    return element;

}

int main(){

    vector<int> arr = {4, 2, 9};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }

    int k = 2;

    cout << "Kth Largest Element is : " << kthLargest(root, k);
    
}

