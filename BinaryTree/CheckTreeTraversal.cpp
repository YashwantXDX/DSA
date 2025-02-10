#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/check-tree-traversal--141628/1

    The simple approach :- 

    1. Make A Tree using PreOrder and InOrder

    2. Traverse That Tree and store the post order ans in an array

    3. Now Check if The PostOrder array is same as postorder (given in question)

    4. If Yes, then it is same tree, else not same tree.

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

int find(int *inorder, int target, int startIndex, int endIndex){

    for(int i = startIndex; i <= endIndex; i++){
        if(inorder[i] == target)
            return i;
    }

    return -1;
}

Node *TreeOne(int *inorder, int *preorder, int inStart, int inEnd, int &index){

    // This is Similar as Binary Search
    if(inStart > inEnd)
        return NULL;
    
    Node *root = new Node(preorder[index]);
    index++;

    // find position of root node
    int pos = find(inorder, root -> data, inStart, inEnd);

    if(pos == -1) return NULL;

    // Left Side
    root -> left = TreeOne(inorder, preorder, inStart, pos - 1, index);

    // Right Side
    root -> right = TreeOne(inorder, preorder, pos + 1, inEnd, index);

    return root;

}

Node *TreeTwo(int *inorder, int *postorder, int inStart, int inEnd, int &index){

    // This is Similar as Binary Search
    if(inStart > inEnd)
        return NULL;
    
    Node *root = new Node(postorder[index]);

    // find position of root node
    int pos = find(inorder, root -> data, inStart, inEnd);

    if(pos == -1) return NULL;

    index--;

    // Right Side
    root -> right = TreeTwo(inorder, postorder, pos + 1, inEnd, index);

    // Left Side
    root -> left = TreeTwo(inorder, postorder, inStart, pos - 1, index);

    return root;

}

void postOrderTraversal(Node *root, vector<int> &postOrder){

    if(root == NULL) return;

    postOrderTraversal(root -> left, postOrder);
    postOrderTraversal(root -> right, postOrder);

    postOrder.push_back(root -> data);

}

bool checktree(int preorder[], int inorder[], int postorder[], int N) 
{ 
    if(preorder[0] != postorder[N - 1])
        return false;

    int preKaIndex = 0, postKaIndex = N - 1;
    Node *firstTree = TreeOne(inorder, preorder, 0, N - 1, preKaIndex);
    
    vector<int> postOrderArr;
    postOrderTraversal(firstTree, postOrderArr);

    for(int i = 0; i < N; i++)
        if(postOrderArr[i] != postorder[i])
            return false;
    
    return true;
    
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

    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 5, 4, 2, 3};
    int postorder[] = {4, 1, 2, 3, 5};

    cout << (checktree ? "Same tree" : "Not Same Tree");

}