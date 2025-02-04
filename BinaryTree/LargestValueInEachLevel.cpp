#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1?page=4&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    This Question is modification of Level Order Traversal,
    We just have to find the max for each level.

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

vector<int> largestValues(Node* root)
{
    vector<int> ans;
    Node *temp;
    queue<Node*> q;
    int maxValue = 0;
    
    q.push(root);
    
    while(!q.empty()){
        
        int size = q.size();
        
        while(size--){
            
            temp = q.front();
            q.pop();
            
            maxValue = max(maxValue, temp -> data);
            
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right)
                q.push(temp -> right);
            
        }
        
        ans.push_back(maxValue);
        maxValue = 0;
        
    }
    
    return ans;
    
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = largestValues(root);

    for(int i : ans)
        cout << i << " ";

}