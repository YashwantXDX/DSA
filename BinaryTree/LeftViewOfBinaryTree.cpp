#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

    Refer Video :- https://www.youtube.com/watch?v=z9GM2HB4mUk&t=5s

    Time Stamp :- 20:02

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


// Aam Tareeka
void leftOfTree(Node *root, vector<int> &ans){

    queue<Node *> q;
    Node *temp;

    q.push(root);

    while(!q.empty()){
        int size = q.size();
        ans.push_back(q.front() -> data);

        while(size--){
            temp = q.front();
            q.pop();

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);

        }
    }

}


// Mentos Tarika
void leftOfTree2(Node *root, vector<int> &ans, int level = 0){

    if(root == NULL) return;

    if(ans.size() == level)
        ans.push_back(root -> data);
    
    leftOfTree2(root -> left, ans, level + 1);
    leftOfTree2(root -> right, ans, level + 1);

    return;

}

vector<int> leftView(Node *root) {
    
    vector<int> ans;
    
    leftOfTree2(root, ans);

    return ans;

}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = leftView(root);

    for(int i : ans)
        cout << i << " ";
}