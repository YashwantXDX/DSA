#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

    Refer Video :- https://www.youtube.com/watch?v=Lk-QYXyPL3g

    Problem Logic :- 

    When We want to search smallest element , we use max heap and if we want to search largest element, we use min heap.

    Because we need to make a small heap of size k, to search efficiently, if disn;t understood, then do watch the video.
    
    1. Create a max heap.

    2. Insert Elements into the heap of size K

    3. Start loop from index K till size and compare if top element of heap is greater than the array element.

    4. If found greater, than pop from heap and push the array element into the heap

    5. Finally, just return the top element of the heap.

*/

int kthSmallest(vector<int> &arr, int k) {

    // Make Max Heap
    priority_queue<int> p;
    
    // Insert Max Heap till k
    for(int i = 0; i < k; i++)
        p.push(arr[i]);
    
    // Now compare the array elements and push and pop the required
    for(int i = k; i < arr.size(); i++){
        if(arr[i] < p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }
    
    return p.top();
}

int main(){

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    
    cout << "K th Smallest Element :- " << kthSmallest(arr, k);

}