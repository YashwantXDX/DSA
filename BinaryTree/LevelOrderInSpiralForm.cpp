#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    
    If The Level is even, then print right to left.
    else print left to right


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

void traverse(Node *root, vector<int> &ans){

    // If we got to the end of the tree
    if(root == NULL) return;

    // Make queue for level
    queue<Node *> q;

    // Make stack for right to left traversal
    stack<Node *> s;

    Node *temp;

    // Define level
    int level = 0;

    // Push the root node
    q.push(root);

    // Iterate till queue gets empty
    while(!q.empty()){

        // Define the size of the current queue
        int size = q.size();

        // Go till Size got 0
        while(size--){

            temp = q.front();
            q.pop();

            // If we get even number of level, go right to left
            if(level % 2 == 0){
                
                // Push the element in stack
                s.push(temp);

                // Check for child in left
                if(temp -> left)
                    q.push(temp -> left);
                
                // Check for child in right
                if(temp -> right)
                    q.push(temp -> right);

            }

            // If we get odd number so left to right traversal
            else{

                // Push the answer in array
                ans.push_back(temp -> data);
                
                if(temp -> left)
                    q.push(temp -> left);
                
                if(temp -> right)
                    q.push(temp -> right);

            }

        }

        // Iteerate till stack got empty for right to left
        while(!s.empty()){

            temp = s.top();
            s.pop();

            ans.push_back(temp -> data);

        }

        // Increase the level as we are going deep
        level++;

    }

    return;

}

vector<int> findSpiral(Node *root){

    vector<int> ans;
    traverse(root, ans);

    return ans;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = findSpiral(root);

    cout << "\n Spiral Traversee \n";
    for(int i : ans)
        cout << i << " ";
}