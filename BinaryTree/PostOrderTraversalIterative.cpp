#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1?page=3&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions

    PreOrder Traversal from right side and reverse the answer array to get in post order

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

vector<int> postOrder(Node* root){
    
    stack<Node *> s;
    vector<int> ans;
    Node *temp;

    s.push(root);

    while(!s.empty()){

        temp = s.top();
        s.pop();

        ans.push_back(temp -> data);

        if(temp -> left)
            s.push(temp -> left);
        
        if(temp -> right)
            s.push(temp -> right);

    }

    reverse(ans.begin(), ans.end());
    return ans;
    
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = postOrder(root);

    for(int i : ans)
        cout << i << " ";

}