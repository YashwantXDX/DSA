#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- 

   

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

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    
    

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
    Node *root = binaryTree();

    vector<int> inorder = {3,1,4,0,2,5};
    vector<int> preorder = {0,1,3,4,2,5};

    Node *ans = buildTree(inorder, preorder);

    print(ans);

}