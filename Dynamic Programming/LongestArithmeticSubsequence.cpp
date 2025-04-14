#include<bits/stdc++.h>
using namespace std;

/*

    Note :- IMPORTANT QUESTION
    
    Problem Link :- https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/


// Unordered Map Approach (can give TLE for some cases)

// Function to find the length of the Longest Arithmetic Progression (LAP)
int lengthOfLongestAP(vector<int>& arr) {
    
    // Get the number of elements in the array
    int n = arr.size();
    
    // If the array has 2 or fewer elements, the LAP is the array itself
    if(n <= 2) return n;
    
    // Create an array of hash maps to store the difference and length of APs ending at each index
    unordered_map<int, int> m[n];
    
    // Variable to store the current difference and final answer
    int diff, ans = 2;
    
    // Traverse the array from the second element to the last
    for(int i = 1; i < n; i++) {
        
        // For each i, check all previous elements
        for(int j = i - 1; j >= 0; j--) {
            
            // Calculate the common difference
            diff = arr[i] - arr[j];
            
            // If an AP with the same difference ends at index j
            if(m[j].count(diff)) {
                
                // Extend the AP and update the length at index i
                m[i][diff] = max(m[i][diff], 1 + m[j][diff]);
                
                // Update the maximum answer
                ans = max(ans, m[i][diff]);
            }
            else {
                // If no such AP exists, initialize a new AP of length 2
                if(!m[j].count(diff))
                    m[i][diff] = 2;
            }
        }
    }
    
    // Return the length of the longest arithmetic progression found
    return ans;
}



int main(){

    vector<int> arr = {1,7,10,13,14,19};

    cout << lengthOfLongestAP(arr);

}