#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/level-order-traversal/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree

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

vector<vector<int>> levelOrder(Node *root){

    vector<vector<int>> ans;
    queue<Node*> q;
    Node *temp;

    q.push(root);

    while(!q.empty()){
        
        // Get the current size
        int size = q.size();
        vector<int> arr;
        
        // While size, push the element in arr and decrease the size to get all the elemtnt in the current level
        while(size--){

            temp = q.front();
            q.pop();

            arr.push_back(temp -> data);

            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);

        }

        // Push the arr to ans for level order elements
        ans.push_back(arr);

    }

    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<vector<int>> ans = levelOrder(root);

    for(int i = 0; i < ans.size(); i++)
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

}