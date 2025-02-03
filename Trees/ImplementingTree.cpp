#include<bits/stdc++.h>
using  namespace std;

class Node{

 public:
    Node *left, *right;
    int data;

    Node(int data){
        this -> data = data;
        left = right = NULL;
    }

};

int main(){

    int x, left, right;
    cout << "Enter root node : ";
    cin >> x;

    Node *root = new Node(x);

    queue<Node*> q;
    q.push(root);
    cout << endl;

    while(!q.empty()){

        Node *temp = q.front();
        q.pop();

        cout << "Enter Left Child of " << temp -> data << " : ";
        cin >> left;

        if(left >= 0){
            temp -> left = new Node(left);
            cout << "Data Added in Left Node\n";
            q.push(temp -> left);
        }

        cout << "Enter Right Child of " << temp -> data << " : ";
        cin >> right;

        if(right >= 0){
            temp -> right = new Node(right);
            cout << "Data Added in Right Node\n";
            q.push(temp -> right);
        }

    }

}