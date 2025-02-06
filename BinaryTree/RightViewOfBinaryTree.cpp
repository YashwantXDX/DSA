#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    Refer Video :- https://www.youtube.com/watch?v=z9GM2HB4mUk&t=5s

    Time Stamp :- 31:08

    The Main Logic Here is Pre Order traversal but check if the level is visited first time or not.

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

void rightOfTree(Node *root, vector<int> &ans, int level = 0){

    if(root == NULL) return;

    if(ans.size() == level)
        ans.push_back(root -> data);
    
    rightOfTree(root -> right, ans, level + 1);
    rightOfTree(root -> left, ans, level + 1);

    
}

vector<int> rightView(Node *root){

    vector<int> ans;

    rightOfTree(root, ans);

    return ans;

}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = rightView(root);

    for(int i : ans)
        cout << i << " ";
}