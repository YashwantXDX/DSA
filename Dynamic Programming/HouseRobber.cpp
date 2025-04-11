#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/house-robber/

    Dynamic Programming is Nothing other than "MEMORIZATION"

*/


// Method 1 - Top Down - O(N), O(N)
int find(int index, vector<int>& nums, int n, vector<int>& dp){

    // if the index is greater than n then it is invalid
    // return 0
    if(index >= n) return 0;

    // check if the index value is already calculated
    // if it is then it will be present in dp table
    if(dp[index] != -1) return dp[index];

    // update the dp[index] with max (chori kiya, chori kar skta tha)
    return dp[index] = max(nums[index] + find(index + 2, nums, n, dp), find(index + 1, nums, n, dp));

}

int rob1(vector<int>& nums) {
    
    int n = nums.size();

    // Take dp table of n + 2 size and -1 as default value
    vector<int> dp(n + 2, -1);

    return find(0, nums, n, dp);
}

// Method 2 - Bottom Up - O(N), O(N)
int rob2(vector<int> &nums) {
    int n = nums.size();

    // Extra space to handle edge cases without index out-of-bounds
    vector<int> dp(n + 2, -1);

    // No money can be robbed from houses beyond the last
    dp[n] = 0;
    dp[n + 1] = 0;

    // Loop from last house to the first
    for(int i = n - 1; i >= 0; i--) {
        // Choose max between:
        // 1. Rob this house + rob houses after skipping one
        // 2. Skip this house and rob the next one
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }

    // Result is max money starting from house 0
    return dp[0];
}


// Method 3 - Space Optimized - O(N), O(1)
int rob3(vector<int> &nums) {
    int n = nums.size();

    // Variables to hold results of future states
    int first = 0;   // dp[i + 1]
    int second = 0;  // dp[i + 2]
    int result;

    // Iterate from last to first house
    for(int i = n - 1; i >= 0; i--) {
        // Calculate max money from current position
        result = max(nums[i] + second, first);

        // Update for next iteration
        second = first;
        first = result;
    }

    return result;
}


int main(){

    vector<int> nums = {2,7,9,3,1};

    cout << rob3(nums);

}