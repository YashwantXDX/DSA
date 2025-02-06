#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?page=1&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions

    Refer Code :- Top View Of Binary Tree
     Just a little bit change to convert that code into this code

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



void find(Node *root, int &leftSide, int &rightSide, int pos){

    if(root == NULL) return;

    leftSide = min(leftSide, pos);

    rightSide = max(rightSide, pos);

    find(root -> left, leftSide, rightSide, pos - 1);
    find(root -> right, leftSide, rightSide, pos + 1);

}

void traverse(Node *root, int pos, vector<int> &ans, vector<int> &level, int currLevel){

    if(root == NULL) return;
    
    // Level Jyada wala update hoga
    if(level[pos] <= currLevel){
        ans[pos] = root -> data;
        level[pos] = currLevel;
    }

    traverse(root -> left, pos - 1, ans, level, currLevel + 1);
    traverse(root -> right, pos + 1, ans, level, currLevel + 1);

}

vector<int> bottomView(Node *root) {

    int leftSide = 0, rightSide = 0;

    find(root, leftSide, rightSide, 0);

    vector<int> ans(rightSide - leftSide + 1);
    vector<int> level(rightSide - leftSide + 1, INT_MIN);

    traverse(root, -1 * leftSide, ans, level, 0);

    return ans;

}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = bottomView(root);

    for(int i : ans)
        cout << i << " ";
}