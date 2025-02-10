#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/construct-tree-1/1

    Refer Video :- https://www.youtube.com/watch?v=XGnLaRwh0bY&t=884s

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

int find(vector<int> &inorder, int target, int startIndex, int endIndex){

    for(int i = startIndex; i <= endIndex; i++){
        if(inorder[i] == target)
            return i;
    }

    return -1;
}

Node *Tree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int index){

    // This is Similar as Binary Search
    if(inStart > inEnd)
        return NULL;
    
    Node *root = new Node(preorder[index]);

    // find position of root node
    int pos = find(inorder, preorder[index], inStart, inEnd);

    // Left Side
    root -> left = Tree(inorder, preorder, inStart, pos - 1, index + 1);

    // Right Side
    root -> right = Tree(inorder, preorder, pos + 1, inEnd, index + (pos - inStart) + 1);

    return root;

}

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    
    int size = inorder.size();

    return Tree(inorder, preorder, 0, size - 1, 0);

}

void print(Node *root){

    queue<Node *> q;
    Node *temp;

    q.push(root);

    while(!q.empty()){

        temp = q.front();
        q.pop();

        cout << temp -> data << " ";

        if(temp -> left)
            q.push(temp -> left);
        
        if(temp -> right)
            q.push(temp -> right);

    }

}

int main(){

    cout << "Enter Root Node : ";
    // Node *root = binaryTree();

    vector<int> inorder = {3,1,4,0,2,5};
    vector<int> preorder = {0,1,3,4,2,5};

    Node *ans = buildTree(inorder, preorder);

    print(ans);

}