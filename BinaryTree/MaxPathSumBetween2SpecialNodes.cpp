#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/maximum-path-sum/1
    
    Refer Video :- https://www.youtube.com/watch?v=RHIXiWHmQ68&t=3165s

    Problem Logic :-

    1. Node ODesn't exist - return 0

    2. Leaf Node aaya :- return root -> data

    3. Left and Right dono exist krte hai :- 
        sum = max(sum, data + left + right)
        return data + max(left, right)
    
    4. if one left only exist :- return data + left

    5. if one right only exist :- return data + right

    
    FOR SPECIAL TEST CASE :- this case will occur when root node is special node.

    So to handle this we have to get the data + max(left, right)

    and before returning the last function check is the root node is special or not?

    if special then update the sum with data + left + right otherwise return the sum;
        
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

int pathSum(Node *root, int &sum){

    if(!root) return 0;

    // If Leaf node?
    if(!root -> left && !root -> right)
        return root -> data;
    
    // Left and right path ka sum
    int left = pathSum(root -> left, sum);
    int right = pathSum(root -> right, sum);

    // Agar node ke dono side exist krte hai
    if(root -> left && root -> right){
        sum = max(sum, root -> data + left + right);
        return root -> data + max(left, right);
    }

    // Only left exist
    if(root -> left)
        return root -> data + left;

    // Only right exist
    if(root -> right)
        return root -> data + right;
    
    return sum;

}

int maxPathSum(Node* root)
{
    
    int sum = INT16_MIN;

    // Find the path sum
    int value = pathSum(root, sum);

    // special case where root node is special node
    // Return sum when root node has both left and right
    if(root -> left && root -> right)
        return sum;
    
    // return max of sum or value if root node is special node
    return max(sum, value);

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();
    int target = 10;

    cout << "Max Path Sum of 2 Special Nodes : " << maxPathSum(root);
}