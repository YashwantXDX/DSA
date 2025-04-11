#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/house-robber/

    Why Memoization Works:
    Without memoization, recursive Fibonacci is exponential (O(2^n)) because it recomputes values many times.

    With memoization, each value from 0 to n is computed only once → Time Complexity: O(n).


*/


// Method 1 - Top Down
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

// Method 2 - Bottom Up
int rob2(vector<int> &nums){

    int n = nums.size();

    vector<int> dp(n + 2, -1);
    dp[n] = 0;
    dp[n + 1] = 0;

    for(int i = n - 1; i >= 0; i--)
        dp[i] = max((nums[i] + dp[i + 2]), dp[i + 1]);
    
    return dp[0];

}

int main(){

    vector<int> nums = {1,2,3,1};

    cout << rob2(nums);

}