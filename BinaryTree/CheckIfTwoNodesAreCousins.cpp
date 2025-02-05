#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1?page=2&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    
    We have to check for x and y to be in same level and they should not have same parents.

    This Approach will Fail the 219th Test Case

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

bool isParent(Node *root, int x, int y){

    if(root == NULL)
        return false;
    
    if(root -> left && root -> right){

        if(root -> left -> data == x && root -> right -> data == y)
            return true;
        
        else if(root -> left -> data == y && root -> right -> data == x)
            return true;

    }

    return false;

}

bool isCousins(Node* root, int x, int y) {
    
    queue<Node *> q;
    Node *temp;
    int level = 0, lvl1, lvl2;

    lvl1 = lvl2 = -1;

    q.push(root);

    while(!q.empty()){

        int size = q.size();

        while(size--){

            temp = q.front();
            q.pop();

            if(temp -> data == x)
                lvl1 = level;
            
            if(temp -> data == y)
                lvl2 = level;
            
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right)
                q.push(temp -> right);

        }

        if(lvl1 != lvl2)
            return 0;
        
        if(lvl1 != -1)
            break;
        
        level++;

    }

    return !isParent(root, x, y);

}

/*

    This Approach will pass all the test cases

*/

bool isCousins2(Node* root, int x, int y) {
    if (!root) return false; // If the tree is empty, return false

    queue<pair<Node*, Node*>> q; // Queue for level-order traversal, storing {node, parent}
    q.push({root, nullptr}); // Start with the root node and no parent

    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        Node* parentX = nullptr; // To store parent of node x
        Node* parentY = nullptr; // To store parent of node y

        for (int i = 0; i < size; i++) { // Process all nodes at the current level
            pair<Node*, Node*> front = q.front(); // Get the front node and its parent
            q.pop(); // Remove it from the queue
            
            Node* node = front.first; // Extract the node
            Node* parent = front.second; // Extract its parent

            if (node->data == x) parentX = parent; // Store parent of x
            if (node->data == y) parentY = parent; // Store parent of y

            // Push left and right children into the queue with the current node as their parent
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }

        // If both x and y are found at the same level, check if they have different parents
        if (parentX && parentY) return parentX != parentY; 
        // If only one of them is found, they are not cousins
        if (parentX || parentY) return false; 
    }

    return false; // If we exit the loop without finding both, return false
}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    int a = 5; int b = 4;

    bool cousin = isCousins(root, a, b);

    cout << endl << (cousin ? "You Are Not Cousin" : "You Are Cousin");
}