#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/minimum-distance-between-bst-nodes/

    Refer Video :- https://www.youtube.com/watch?v=Rq1II71_Glw&t=1718

    Just Remember, Binary Search Tree ke problems me hmehsa inorder kaise kaam kr rha hai orr prev node ko kaise manage kr rhe hai ye dhyaan rkhna hai

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

void getMin(Node *root, int &prev, int &ans){

    if(!root) return;

    // Left Jao
    getMin(root -> left, prev, ans);

    // Minimum value get karo

    // Check kro ki prev ki INT_MIN wali value update hai ya nahi
    if(prev != INT_MIN)
        ans = min(ans, root -> data - prev);
    
    // prev me root ki value daal do
    prev = root -> data;

    // Right Jao
    getMin(root -> right, prev, ans);

}

int minDiffInBST(Node* root) {
   int prev = INT_MIN, ans = INT_MAX;

   getMin(root, prev, ans);

   return ans; 
}

int main(){

    vector<int> arr = {1,0,48,12,49};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }

    cout << "Minimum Distance Between BST Nodes : " << minDiffInBST(root);
    
}

