#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

    Refer Video :- https://www.youtube.com/watch?v=XGnLaRwh0bY&t=3283s

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

Node *Tree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int index){

    // This is Similar as Binary Search
    if(inStart > inEnd)
        return NULL;
    
    Node *root = new Node(postorder[index]);

    // find position of root node
    int pos = find(inorder, postorder[index], inStart, inEnd);

    // Right Side
    root -> right = Tree(inorder, postorder, pos + 1, inEnd, index - 1);

    // Left Side
    root -> left = Tree(inorder, postorder, inStart, pos - 1, index - (inEnd - pos) - 1);

    return root;

}

Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
    
    int size = inorder.size();

    return Tree(inorder, postorder, 0, size - 1, size - 1);

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

    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *ans = buildTree(inorder, postorder);

    print(ans);

}