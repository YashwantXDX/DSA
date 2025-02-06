#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions

    Refer Video :- https://www.youtube.com/watch?v=z9GM2HB4mUk&t=5s

    Time Stamp :- 45:32

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


// Aam Aproach
vector<int> topView(Node *root) {

    int leftSide = 0, rightSide = 0;

    // Find the leftmost side and rightmost side
    find(root, leftSide, rightSide, 0);   

    // ans and index array with width of binary tree
    vector<int> ans(rightSide - leftSide + 1);
    vector<bool> index(rightSide - leftSide + 1);

    // Queue for nodes and their indexes
    queue<Node *> q;
    queue<int> indexQ;

    // Push the root node and index
    q.push(root);

    // We have done this to get positive integer fo rleft Side as it is in negetive
    indexQ.push(-1 * leftSide);

    while(!q.empty()){

        Node *temp = q.front();
        q.pop();

        int pos = indexQ.front();
        indexQ.pop();

        // If we found any non visited element then put it in answer array otherwise leave it
        if(index[pos] == 0){
            ans[pos] = temp -> data;
            index[pos] = 1;
        }

        // To move left, go pos - 1
        if(temp -> left){
            q.push(temp -> left);
            indexQ.push(pos - 1);
        }

        // To move right, go pos + 1
        if(temp -> right){
            q.push(temp -> right);
            indexQ.push(pos + 1);
        }

    }

    return ans;

}

void find(Node *root, int &leftSide, int &rightSide, int pos){

    if(root == NULL) return;

    leftSide = min(leftSide, pos);

    rightSide = max(rightSide, pos);

    find(root -> left, leftSide, rightSide, pos - 1);
    find(root -> right, leftSide, rightSide, pos + 1);

}

// Mentos Approach
// Hume 2 chizo ka Dhyaan Rkhna hai
// 1. Level 2. Position

void traverse(Node *root, int pos, vector<int> &ans, vector<int> &level, int currLevel){

    if(root == NULL) return;

    if(level[pos] > currLevel){
        ans[pos] = root -> data;
        level[pos] = currLevel;
    }

    traverse(root -> left, pos - 1, ans, level, currLevel + 1);
    traverse(root -> right, pos + 1, ans, level, currLevel + 1);

}

vector<int> topView2(Node *root) {

    int leftSide = 0, rightSide = 0;

    find(root, leftSide, rightSide, 0);

    vector<int> ans(rightSide - leftSide + 1);
    vector<int> level(rightSide - leftSide + 1, INT16_MAX);

    traverse(root, -1 * leftSide, ans, level, 0);

    return ans;

}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = topView2(root);

    for(int i : ans)
        cout << i << " ";
}