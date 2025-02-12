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
    PostOrder - Left Right Node
*/
vector<int> postorder(Node *root){

    vector<int> ans;

    while(root){

        // Right Part doesn't exist
        if(!root -> right){
            ans.push_back(root -> data);
            root = root -> left;
        }

        // Right part exist
        else{
            
            Node *curr = root -> right;
            
            // Check is current left exist and is not equal to root (traversed)
            while(curr -> left && curr -> left != root)
                curr = curr -> left;
                
            // Right Subtree not traversed
            if(curr -> left == NULL){
                curr -> left = root;
                ans.push_back(root -> data);
                root = root -> right;
            }

            // Right Subtree Traversed
            else{
                curr -> left = NULL;
                root = root -> left;
            }

        }

    }

    // reverse The Answer for Post Order
    reverse(ans.begin(), ans.end());

    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = postorder(root);

    for(int i : ans)
        cout << i << " ";
}