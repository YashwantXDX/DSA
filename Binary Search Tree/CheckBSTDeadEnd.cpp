#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

    Refer Video :- https://www.youtube.com/watch?v=YKo8QaW02z8

    Problem Logic :-

    Hume har Node pe uksa range dhundhna hai, orr range milte hi check krnaa he ki high - low = 1;

    agar 1 hai mtlb dead end hai, return kar do ki dead end hai right or left dono ka check krne ke baad

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

Node *insertData(Node *root, int target){

    if(!root){
        return new Node(target);
    }

    if(root -> data > target){
        root -> left = insertData(root -> left, target);
    }

    else{
        root -> right = insertData(root -> right, target);
    }

    return root;
}

void printData(Node *root){

    while(root){

        if(!root -> left){
            cout << root -> data << " ";
            root = root -> right;
        }

        else{

            Node *curr = root -> left;

            while(curr -> right && curr -> right != root)
                curr = curr -> right;
            
            if(curr -> right == NULL){
                curr -> right = root;
                root = root -> left;
            }

            else{
                cout << root -> data << " ";
                root = root -> right;
                curr -> right = NULL;
            }

        }

    }

}

bool find(Node *root, bool &dead, int low, int high){

    // Agar Node hi NULL hai to dead end kaha se hoga
    if(!root) return 0;

    // Agar leaf node aa gya to check kro hi
    // left me root -> data - low = 1 to nhi
    // Right me high - root -> data = 1 to nhi
    if(!root -> left && !root -> right){

        if(root -> data - low == 1 && high - root -> data == 1)
            return true;
    }

    // Ab yhi chiz left ke liye kro orr right ke liye kro
    // agar dono me se kahi bhi 1 aaya to dead end hai vrna nhi hai
    return find(root -> left, dead, low, root -> data) || 
    find(root -> right, dead, root -> data, high);


}

bool isDeadEnd(Node *root){

    bool dead = false;

    find(root, dead, 0, INT_MAX);

    return dead;

}

int main(){

    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    Node *root = NULL;

    for(int i = 0; i < arr.size(); i++){
        root = insertData(root, arr[i]);
    }
    
}

