#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/array-to-bst4443/1

    Refer Video :- https://www.youtube.com/watch?v=Rq1II71_Glw

    Problem Logic :-

    Just like Binary Search, we have to find the mid and start creating the node left and right till start > end.

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

void find(vector<int> &nums, Node* &ans, int start, int end){

    if(start > end) return;

    int mid = start + (end - start) / 2;

    if(!ans)
        ans = new Node(nums[mid]);
    
    find(nums, ans -> left, start, mid - 1);
    find(nums, ans -> right, mid + 1, end);

}

Node *sortedArrayToBST(vector<int> &nums){
    Node *ans = NULL;
    find(nums, ans, 0, nums.size() - 1);

    return ans;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7};
    Node *root = sortedArrayToBST(arr);

}

