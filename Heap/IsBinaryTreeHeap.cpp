#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

    Refer Video :- https://www.youtube.com/watch?v=ANjoYpXpDaw&t=621

    Problem Logic :- 

    To solve this problem, hume 2 chize check krni hai

    1. Complete Binary tree Hai ya nhi
    2. Parent apne dono baccho se bda hai ya nhi

    dono me se kuch bhi fail hua means vo Max heap nhi hai

    Note :- Complete binary tree check krne ke liye hume tree ke nodes gin na hai orr indexing de deni hai. For eg. agar nodes 6 hai to unke index 0-5 tk hi rhne chahiye >= 6 nhi hona chahiye.

    index >= total_nodes - Formula for CBT

*/

class Node{
    public:
    int data; Node *left, *right;
    Node(int data){
        this ->data = data;
        left = right = NULL;
    }
};

int countNodes(Node* tree){

    if(!tree) return 0;

    return 1 + countNodes(tree -> left) + countNodes(tree -> right);

}

bool isMaxHeap(Node *tree, int index, int size){

    if(!tree) return 1;

    if(index >= size) return 0;

    bool left = isMaxHeap(tree -> left, 2 * index + 1, size);

    bool right = isMaxHeap(tree -> right, 2 * index + 2, size);

    return left && right;

}

bool checkMaxHeap(Node *tree){

    if(tree -> left){

        if(tree -> data < tree -> left -> data)
            return 0;
        
        // Agar left side se max heap nhi banta to return kar do 0
        if(!checkMaxHeap(tree -> left))
            return 0;

    }

    if(tree -> right){

        if(tree -> data < tree -> right -> data)
            return 0;
        
        // Simply return if right side is maxheap or not
        return checkMaxHeap(tree -> right);

    }

    return 1;

}

bool isHeap(struct Node* tree) {
    
    // Count Nodes
    int nodes = countNodes(tree);

    // Is Complete binary tree?
    // tree bhejo, index bhejo, total nodes bhejo
    bool valid = isMaxHeap(tree, 0, nodes);

    if(!valid) return 0;

    // Check for Max heap
    bool ans = checkMaxHeap(tree);

    return ans;

}
