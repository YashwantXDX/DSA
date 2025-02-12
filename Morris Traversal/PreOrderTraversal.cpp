#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
    
    Refer Video :- https://www.youtube.com/watch?v=TvfGWVAv_cc&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=110

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

Node *binaryTree(){

    int x; cin >> x;

    if(x == -1) return NULL;

    Node *temp = new Node(x);

    // Left Side
    cout << "Enter Left Side of " << x << " : ";
    temp -> left = binaryTree();

    // Right Side
    cout << "Enter Right Side of " << x << " : ";
    temp -> right = binaryTree();

    return temp;
}

/*
    Inorder - Left Node Right
*/
vector<int> preorder(Node *root){

    vector<int> ans;

    while(root){

        // Left Part doesn't exist
        if(!root -> left){
            ans.push_back(root -> data);
            root = root -> right;
        }

        // Left part exist
        else{
            
            Node *curr = root -> left;

            while(curr -> right && curr -> right != root)
                curr = curr -> right;
                
            // Left Subtree not traversed
            if(curr -> right == NULL){
                curr -> right = root;
                ans.push_back(root -> data);
                root = root -> left;
            }

            // Left Subtree Traversed
            else{
                curr -> right = NULL;
                root = root -> right;
            }

        }

    }

    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = preorder(root);

    for(int i : ans)
        cout << i << " ";
}