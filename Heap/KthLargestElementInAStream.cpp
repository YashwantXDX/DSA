#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

    Problem Logic :- 

    1. Make a min heap 
    2. Insert Elements in min heap till k - 1 and ans.push(-1)
    3. add the k - 1 element into the min heap and ans.push(arr[k])
    4. do the find kth llargest element logic here
    5. return the ans

*/

vector<int> kthLargest(int k, vector<int> &arr, int n) {
        
    vector<int> ans;
    
    if(k == 1){
        for(int i = 0; i < n; i++)
            ans.push_back(arr[i]);
        
        return ans;
    }
    
    priority_queue<int, vector<int>, greater<int>> p;
    
    for(int i = 0; i < k - 1; i++){
        ans.push_back(-1);
        p.push(arr[i]);
    }
    
    p.push(arr[k - 1]);
    ans.push_back(p.top());
    
    for(int i = k; i < n; i++){
        if(arr[i] >= p.top()){
            p.pop();
            p.push(arr[i]);
        }
        ans.push_back(p.top());
    }
    
    return ans;
    
}

int main(){

    vector<int> arr = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    vector<int> ans = kthLargest(k, arr, arr.size());

}