#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

    Refer Video :- https://www.youtube.com/watch?v=GMZ3DcXiHHQ&t=2382

    Problem Logic :-

    Just Morris Traversal for saving Space, and take two varible to store gadbad values.

    After traversing just swap the first and second

    we know that inorder traversal will give sorted way so just swap the two gadbad value.


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

void correctBST(Node* root) {
    
    Node *first = NULL, *second = NULL, *last = NULL, *present = NULL;

    while(root){

        // Left nhi hai to right me jao
        if(!root -> left){

            // Right Jaane ke phle last or present ko update karo

            // Last ke andar present daalo and present ke andar root node ko daalo
            last = present;
            present = root;

            // Check karo ki kahi kuch gadbad to nhi?
            if(last && last -> data > present -> data){

                // Agar first time gadbad hai?
                // To first orr second me data update kro

                // first me last ko dalna hai
                if(!first)
                    first = last;
                
                // second me present node jayega
                // agar second time gadbad hoti hai to sirf second ko update krna hai
                second = present;

            }

            root = root -> right;

        }

        // Right hai
        else{

            Node *temp = root -> left;

            // Left ke rightmost me jao
            // orr ye bhi dekho ki mera right kahi
            // root ko to point nhi kar rha
            while(temp -> right && temp -> right != root)
                temp = temp -> right;
            
            // Hume temp -> right null milaa
            if(!temp -> right){
                temp -> right = root;
                root = root -> left;
            }

            // Hume temp -> right me root mila
            else{
                temp -> right = NULL;

                // Same Conditions jo humne upar check kiya hai
                last = present;
                present = root;

                if(last && last -> data > present -> data){
                    if(!first)
                        first = last;
                    
                    second = present;
                }

                root = root -> right;
            }
            
        }

    }

    // Swapping Data
    first -> data = first -> data ^ second -> data;
    second -> data = first -> data ^ second -> data;
    first -> data = first -> data ^ second -> data;
    
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


int main(){

    vector<int> arr = {10, 5, 8, 2, 20};
    Node *root = NULL;

    correctBST(root);

    printData(root);
    
}

