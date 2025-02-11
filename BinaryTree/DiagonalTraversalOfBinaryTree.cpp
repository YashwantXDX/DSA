#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

    Refer Video :- https://www.youtube.com/watch?v=aBqPnkXmvpY&t=2189

    Problem Logic : 

    Find the length of Left Most Side.

    Make a 2-D Array which will store the element in each Diagonal.

    Now, We will find the diagonal elements by Left and Right index. 

    Now transfer all the elements of 2-D array into 1-D ans array and return ans.

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

void find(Node *root, int pos, int &left){

    if(root == NULL) return;

    // Find the Left Most Element Level
    left = max(pos, left);

    // Find For Left
    find(root -> left, pos + 1, left);

    // Find For Right
    find(root -> right, pos, left);

}

void findDiagonal(Node *root, vector<vector<int>> &traverse, int pos){

    if(root == NULL) return;

    // Left Level Pushing
    traverse[pos].push_back(root -> data);

    findDiagonal(root -> left, traverse, pos + 1);
    findDiagonal(root -> right, traverse, pos);

}

vector<int> diagonal(Node *root) {

    int left = 0;
    find(root, 0, left);

    vector<vector<int>> traverse(left + 1);

    findDiagonal(root, traverse, 0);

    vector<int> ans;

    for(int i = 0; i < traverse.size(); i++)
        for(int j = 0; j < traverse[i].size(); j++)
            ans.push_back(traverse[i][j]);
    
    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = diagonal(root);

    for(int i : ans)
        cout << i << " ";
}