#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

    Refer Video :- https://www.youtube.com/watch?v=YKo8QaW02z8&t=3028

    Problem Logic :-

    Hume do stack lene hai, ek r1 ke liye orr ek r2 ke lye.

    dono stack ko r1 and r2 ke left part se bhar do taaki dono ascending order me rhe.

    ab hum jaise array me aage piche krte hai vaisi hi yha karna hai

    s1 ka top s2 se chota hai to s2 ke element ko pop kro taki aage bdhee

    orr agar s2 ka top s1 se chota hai to s1 ke element ko pop kro

    orr agar dono same same hai to ans me push kr do orr dono ko ek ek se aage bdha to means pop kro

    orr har pop ke baad jo bhi element pop hua hai uske right me jaa ke saare left part ke stack me push kar do
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

vector<int> findCommon(Node *r1, Node *r2) {
        
    vector<int> ans;
    
    stack<Node *> s1, s2;
    
    // Push Left Part of r1 into s1
    while(r1){
        s1.push(r1);
        r1 = r1 -> left;
    }
    
    // Push Left Part of r2 into s2
    while(r2){
        s2.push(r2);
        r2 = r2 -> left;
    }
    
    // Now the main part
    while(!s1.empty() && !s2.empty()){
        
        // Check if the data matchs
        if(s1.top() -> data == s2.top() -> data){
            
            ans.push_back(s1.top() -> data);
            
            r1 = s1.top() -> right;
            r2 = s2.top() -> right;
            s1.pop();
            s2.pop();
            
            // Push Left part of r1 and r2 into their stacks
            while(r1){
                s1.push(r1);
                r1 = r1 -> left;
            }
            
            while(r2){
                s2.push(r2);
                r2 = r2 -> left;
            }
            
        }
        
        // Agar s1 ke top ki value badi hai to s2 ko khali kar ke aage bdhana pdega
        // because dono ascending order me hai to upar se chota orr niche bda hai
        else if(s1.top() -> data > s2.top() -> data){
            
            r2 = s2.top() -> right;
            s2.pop();
            
            // Push Left Part of r2 into s2
            while(r2){
                s2.push(r2);
                r2 = r2 -> left;
            }
            
        }
        
        // Agar s2 ke top ki value badi hai to s1 ko khali kar ke aage bdhana pdega
        // because dono ascending order me hai to upar se chota orr niche bda hai
        else{
            
            r1 = s1.top() -> right;
            s1.pop();
            
            // Push Left Part of r1 into s1
            while(r1){
                s1.push(r1);
                r1 = r1 -> left;
            }
            
        }
        
    }
    
    return ans;
    
}

int main(){

    vector<int> arr1 = {5, 1, 0, 4, 10, 7, 9};
    vector<int> arr2 = {10, 7, 20, 4, 9};

    Node *root1 = NULL;
    Node *root2 = NULL;

    for(int i = 0; i < arr1.size(); i++){
        root1 = insertData(root1, arr1[i]);
    }
    for(int i = 0; i < arr2.size(); i++){
        root2 = insertData(root2, arr2[i]);
    }

    vector<int> ans = findCommon(root1, root2);

    for(int i : ans)
        cout << i << " ";
    
}

