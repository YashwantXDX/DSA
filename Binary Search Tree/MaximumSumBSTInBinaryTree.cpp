#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

    Refer Video :- https://www.youtube.com/watch?v=R7UifBXBPXU

    Similar Approach as This Video

    Problem Logic :-
    
    Check if that present node is BST or not, by checking its left and right, and if it is or their left or right is then just update the maximun size.

    In chizo ka Dhyaan Rkhna hai :-

    1. No Root then just return Box

    2. If There is Root

    left tree me dhundo, right tree me dhundo

    check karo ki dono valid BST hai?
    agar hai

    to ek head ptr bnao box type ka and 
    head -> sum = root -> data + right -> sum + left -> sum

    head -> min ko minimim of root -> data and left -> min
    head -> max ko maximum of root -> data and right -> max

    maxSum ko update kro as max of maxSum and head -> sum, jo bhi bda ho vo maxSum me jaye

    return kr do head ko

    vrna agar valid bst nhi hai to returnkr do false ya aaisa kuch.

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

class Box{
    public:
        bool BST;
        int sum, min, max;

        Box(){
            BST = 1;
            sum = 0;
            min = INT_MAX;
            max = INT_MIN;
        }
};

Box *find(Node *root, int &maxSum){

    // No Root exist?
    if(!root)
        return new Box();
    
    // Root Exist
    Box *left = find(root -> left, maxSum);
    Box *right = find(root -> right, maxSum);

    // Valid BST?
    if(left -> BST && right -> BST && left -> max < root -> data && right -> min > root -> data){

        // head ptr
        Box *head = new Box();

        // head ke sum ko update kro
        head -> sum = root -> data + left -> sum + right -> sum;

        // head ke min and max value ko update kro
        head -> min = min(root -> data, left -> min);
        head -> max = max(root -> data, right -> max);

        // maxSum ko update kro
        maxSum = max(maxSum, head -> sum);

        return head;
    }

    // Not Valid BST
    else{
        left -> BST = 0;
        return left;
    }

}

int maxSumBST(Node* root) {
    
    int maxSum = 0;

    find(root, maxSum);

    return maxSum;

}

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

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    cout << "Largest BST size is : " << maxSumBST(root);

}