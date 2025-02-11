#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

    Refer Video :- https://www.youtube.com/watch?v=aBqPnkXmvpY&t=43

    Problem Logic :- 
    
    Traverse The Tree in Level Order, Make two 2-D vectors , one for negetive(left) and one for positive(right)
    
    initialize the size of vector of positive with the rightmost level of the element and do the same for negetive with leftmost level.

    Now, Simply do the traversal thing of Level Order traversal and put the elements in their respective vectors.

    After that , simply traverse the negetive vector from end, as we know the counting duhh.. and then go to the positive so we will get the answer of 
    Vertical Traversal.

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

void find(Node *root, int pos, int &left, int &right){

    if(root == NULL) return;

    left = min(pos, left);
    right = max(pos, right);

    find(root -> left, pos - 1, left, right);
    find(root -> right, pos + 1, left, right);

}

vector<int> verticalOrder(Node *root)
{
    
    int left = 0, right = 0;

    // Find the leftmost level and rightmost level
    find(root, 0, left, right);

    // 2 D vectors
    vector<vector<int>> negetive(abs(left) + 1); // Left part will be in negetive so abs the left
    vector<vector<int>> positive(right + 1);

    // Now Level Order traversal
    queue<Node *> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while(!q.empty()){

        Node *temp = q.front(); q.pop();
        int pos = index.front(); index.pop();

        // Agar data ka level 0 se bda hua ya 0 hua to vo positve wale side me hai
        if(pos >= 0)
            positive[pos].push_back(temp -> data);
        
        // Vrna vo negetive side me hai
        else
            negetive[abs(pos)].push_back(temp -> data);
        
        
        // Level Order Continue
        if(temp -> left){
            q.push(temp -> left);
            index.push(pos - 1);
        }

        if(temp -> right){
            q.push(temp -> right);
            index.push(pos + 1);
        }

    }

    // Now make the answer array and put the values from negetive and positive vectors
    vector<int> ans;

    for(int i = negetive.size() - 1; i > 0; i--)
        for(int j = 0; j < negetive[i].size(); j++)
            ans.push_back(negetive[i][j]);
        
    for(int i = 0; i < positive.size(); i++)
        for(int j = 0; j < positive[i].size(); j++)
            ans.push_back(positive[i][j]);
    
    return ans;

}


int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    vector<int> ans = verticalOrder(root);

    for(int i : ans)
        cout << i << " ";
}