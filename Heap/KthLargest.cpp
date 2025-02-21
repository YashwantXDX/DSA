#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/kth-largest-element-in-an-array/description/

    Refer Video :- https://www.youtube.com/watch?v=Lk-QYXyPL3g&t=2132

    Problem Logic :- 

    When We want to search smallest element , we use max heap and if we want to search largest element, we use min heap.

    Because we need to make a small heap of size k, to search efficiently, if didn;t understood, then do watch the video.
    
    1. Create a min heap.

    2. Insert Elements into the heap of size K

    3. Start loop from index K till size and compare if top element of heap is smaller than the array element.

    4. If found smaller, than pop from heap and push the array element into the heap

    5. Finally, just return the top element of the heap.

*/

int findKthLargest(vector<int>& nums, int k) {
    
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> p;

    // Insert Elements in min heap
    for(int i = 0; i < k; i++)
        p.push(nums[i]);

    // Compare and perform required operations
    for(int i = k; i < nums.size(); i++){
        if(nums[i] > p.top()){
            p.pop();
            p.push(nums[i]);
        }
    }

    return p.top();

}

int main(){

    vector<int> arr = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    cout << "K th Smallest Element :- " << findKthLargest(arr, k);

}