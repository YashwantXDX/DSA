#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

    Refer Video :- https://www.youtube.com/watch?v=HZWTEeOqF4c&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=129

*/

int findSubarray(vector<int> &arr) {
        
    int totalCount = 0, prefixSum = 0;
    
    unordered_map<int, int> m;
    
    // 0 element ko count kar lo 1 se (Edge Case)
    m[0] = 1; 
    
    // Prefix Sum dhundo orr map me check kro ki vo present hai ya nhi orr agar present hai to total count bdhao vrna map pe add kr do
    for(int i = 0; i < arr.size(); i++){
        prefixSum += arr[i];
        
        if(m[prefixSum]){
            totalCount += m[prefixSum];
            m[prefixSum]++;
        }
        
        else
            m[prefixSum] = 1;
    }
    
    return totalCount;
}

int main(){

    vector<int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};

    cout << findSubarray(arr);

}