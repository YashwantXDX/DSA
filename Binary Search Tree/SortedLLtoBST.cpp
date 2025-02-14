#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1

    Refer Video :- https://www.youtube.com/watch?v=GMZ3DcXiHHQ

    Problem Logic :-

    Just make the LinkedList to array.

    And Now make that sorted array to BST. Same like we do in Binary Search, we take the mid and put that into tree node, the mid's left part is left and mid's right part is right.

    Do this till start > end.

*/

class LNode{
    public:
        int data;
        LNode *next;

        LNode(int data){
            this -> data = data;
            next = NULL;
        }
};

class TNode{
    public:
        int data;
        TNode *left, *right;

        TNode(int data){
            this -> data = data;
            left = right = NULL;
        }
};

TNode *insertData(TNode *root, int target){

    if(!root){
        return new TNode(target);
    }

    if(root -> data > target){
        root -> left = insertData(root -> left, target);
    }

    else{
        root -> right = insertData(root -> right, target);
    }

    return root;
}

void printData(TNode *root){

    while(root){

        if(!root -> left){
            cout << root -> data << " ";
            root = root -> right;
        }

        else{

            TNode *curr = root -> left;

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

void makeLLtoArr(LNode *head, vector<int> &arr){
    while(head){
        arr.push_back(head -> data);
        head = head -> next;
    }
}

void makeTree(vector<int> &arr, TNode* &root, int start, int end){
    
    if(start > end) return;
    
    int mid = end + (start - end) / 2;
    
    if(!root)
        root = new TNode(arr[mid]);
    
    makeTree(arr, root -> left, start, mid - 1);
    
    makeTree(arr, root -> right, mid + 1, end);

    
}

TNode *sortedListToBST(LNode *head) {
    
    vector<int> arr;
    
    // Make LL to Array
    makeLLtoArr(head, arr);
    
    // Now Make Balanced BST
    TNode *root = NULL;
    
    makeTree(arr, root, 0, arr.size() - 1);
    
    return root;
    
}

int main(){

    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    TNode *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }
    
}

