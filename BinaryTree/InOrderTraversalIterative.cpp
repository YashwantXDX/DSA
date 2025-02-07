#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1?page=3&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions

    First Time visit, Push in stack in 
    Right Node Left.

    Second Time visit, Push them into array after check that they have been visited in twice not once.

    We need Two Stack, One for element and second for their count.

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

vector<int> inOrder(Node* root){
    
    stack<Node *> s;
    stack<int> count;
    vector<int> ans;
    Node *temp;
    int cnt;

    s.push(root);
    count.push(0);

    while(!s.empty()){

        temp = s.top();
        s.pop();
        cnt = count.top();
        count.pop();

        if(cnt == 1)
            ans.push_back(temp -> data);
        
        else{

            if(temp -> right){
                s.push(temp ->right);
                count.push(0);
            }

            s.push(temp);
            count.push(1);

            if(temp -> left){
                s.push(temp ->left);
                count.push(0);
            }

        }

    }

    return ans;
    
}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = inOrder(root);

    for(int i : ans)
        cout << i << " ";

}