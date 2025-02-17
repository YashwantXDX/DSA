#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/largest-bst/1

    Refer Video :- https://www.youtube.com/watch?v=R7UifBXBPXU

    Problem Logic :-
    
    Check if that present node is BST or not, by checking its left and right, and if it is or their left or right is then just update the maximun size.

    In chizo ka Dhyaan Rkhna hai :-

    1. Leaf Node hai to simple BST : 1, size : 1, min: data, max: data

    2. Agar sirf left node present hai to, left side ko dekho ki BST hai ya nhi, vo dekhne ke baad agar milta hai to BST : 1, size : size + 1, min : left -> data.
    totalSize = max(totalSize, left -> size)

    3. same right ke liye bhi hai, bas isme hume sirf max : right -> data krna hai.
    totalSize = max(totalSize, right -> size)

    4. Agar Dono present hai, to hume left orr right dono ke liye nikaalna hai orr check krna hai ki jo node pe hum ha vo BST hai ya nhi, agar BST mil jata hai to 
    BST : 1, size = size + left -> size + right -> size (jo node pr hum hai uskla size by default 1 rhega)
    totalSize = max(totalSize, head -> size)

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
    int data, min, max, size;

    Box(int data){
        this -> data = data;
        BST = 1;
        size = 1;
        min = data;
        max = data;
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

Box *find(Node *root, int &maxSize){

    // If Leaf Node
    if(!root -> left && !root -> right){
        maxSize = max(maxSize, 1);
        return new Box(root -> data);
    }
    
    // If Left Subtree only exist
    // size ko ek se bdha do
    // hume left se max chahiye kyoki BST me
    // left < root < right rhta hai hmesha
    else if(!root -> right && root -> left){

        Box *head = find(root -> left, maxSize);

        // Execute this when we got that the current node
        // is BST
        if(head -> BST && head -> max < root -> data){
            head -> size++;
            head -> max = root -> data;
            maxSize = max(maxSize, head -> size);
        }

        // If this node is not BST
        else
            head -> BST = 0;

        return head;

    }

    // If Right Subtree only exist
    // size ko ek se bdha do
    // hume right se min chahiye kyoki BST me
    // left < root < right rhta hai hmesha
    else if(root -> right && !root -> left){

        Box* head = find(root -> right, maxSize);

        // Execute this when we got that the current node
        // is BST
        if(head -> BST && head -> min > root -> data){

            head -> min = root -> data;
            head -> size++;
            maxSize = max(maxSize, head -> size);

        }

        // If this node is not BST
        else
            head -> BST = 0;

        return head;

    }

    // If Both left and right are present then
    else{

        Box *left = find(root -> left, maxSize);
        Box *right = find(root -> right, maxSize);

        // Execute this when we got a valid BST
        // i.e. left part and right part are BST
        // left -> max should be less than root -> data
        // and root -> data should be less than right -> min, then only it is a valid BST
        if(left -> BST && right -> BST && left -> max < root -> data && root -> data < right -> min){

            Box *head = new Box(root -> data);

            // head ka size by default 1 hai
            head -> size += left -> size + right -> size;
            head -> min = left -> min;
            head -> max = right -> max;

            maxSize = max(maxSize, head -> size);

            return head;
        }

        else{
            left -> BST = 0;
            return left;
        }

    }

}

int largestBst(Node *root)
{
    
    int totalSize = 0;

    find(root, totalSize);

    return totalSize;

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();

    cout << "Largest BST size is : " << largestBst(root);

}