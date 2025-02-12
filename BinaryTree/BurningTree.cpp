#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/burning-tree/1
    
    Refer Video :- https://www.youtube.com/watch?v=RHIXiWHmQ68

    Problem Logic :-

    1. Start From the root Node, go left and right.

    2. While Traversing Left and Right, hume dekhna hai ki agar koi burning hai to kitna time lgega use burn hone me vo return krna hai negetive me vrna simply uski height return kr do.

    3. Timer me left part ka height ya burning time and right part ka height ya burning time ko add kr lo.

    4. Last me hume jo element se burning chalu hai uski height or timer me jo bhi bda hai use return krva dena hai.

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

int burn(Node *root, int &timer, int &target){

    // Doesn't Exist?
    if(!root) 
        return 0;

    // If Exist Or Burning element bhi hai
    if(root -> data == target) 
        return -1;

    // Normal element hai?

    // Left Jao
    int left = burn(root -> left, timer, target);

    // Right Jao
    int right = burn(root -> right, timer, target);

    // Agar Burn aa rha hai left se
    if(left < 0){
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    // Agar Burn aa rha hai right se
    if(right < 0){
        timer = max(timer, left + abs(right));
        return right - 1;
    }

    // Agar Burn Nhi hai dono side me to height bhej do
    return 1 + max(left, right);

}

void findBurning(Node *root, int &target, Node* &burningElement){

    if(!root || burningElement) return;

    if(root -> data == target){
        burningElement = root;
        return;
    }

    findBurning(root -> left, target, burningElement);
    findBurning(root -> right, target, burningElement);

}

int findHeightOfBurning(Node *root){

    if(!root)
        return 0;
    
    return 1 + max(findHeightOfBurning(root -> left), findHeightOfBurning(root -> right));

}

int minTime(Node* root, int target) {
    
    int timer = 0;

    burn(root, timer, target);

    // Height Dhundo target node ki

    Node *burningElement = NULL;

    findBurning(root, target, burningElement);

    int heightOfBurningElement = findHeightOfBurning(burningElement) - 1;

    return max(timer, heightOfBurningElement);

    

}

int main(){

    cout << "Enter Root Node : ";
    Node *root = binaryTree();
    int target = 10;

    cout << "Time To Burn The Tree : " << minTime(root, target);
}