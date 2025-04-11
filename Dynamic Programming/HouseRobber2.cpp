#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/house-robber-ii/

    Dynamic Programming is Nothing other than "MEMORIZATION"

*/

// Recursive helper function with memoization
int find(int index, int n, vector<int> &nums, vector<int> &dp){

    // Base case: If index is out of bounds, return 0
    if(index >= n) return 0;

    // If this subproblem has already been solved, return the stored result
    if(dp[index] != -1) return dp[index];

    // Choice 1: Rob current house and skip next (index + 2)
    // Choice 2: Skip current house and check next (index + 1)
    // Store the maximum of both choices in dp and return it
    return dp[index] = max(nums[index] + find(index + 2, n, nums, dp), find(index + 1, n, nums, dp));
}

// Method 1 - Top Down DP with Memoization - O(N), O(N)
int rob1(vector<int> &nums){

    // Get the total number of houses
    int n = nums.size();

    // If there's only one house, just rob it
    if(n == 1) return nums[0];

    // Create two dp arrays initialized with -1
    // dp1 considers robbing from house 0 to n-2
    vector<int> dp1(n + 2, -1);
    // dp2 considers robbing from house 1 to n-1
    vector<int> dp2(n + 2, -1);

    // Return the max between robbing from 0 to n-2 and from 1 to n-1
    return max(find(0, n - 1, nums, dp1), find(1, n, nums, dp2));
}

// Method 2 - Bottom Up Approach - O(N), O(N)
int rob2(vector<int> &nums){

    // Get the number of houses
    int n = nums.size();

    // If only one house, return its value
    if(n == 1) return nums[0];

    // Create two dp arrays with extra padding and initialize with -1
    vector<int> dp1(n + 2, -1);
    vector<int> dp2(n + 2, -1);

    // Base cases for dp1 (0 to n-2)
    dp1[n] = 0;       // No money if starting from house n
    dp1[n - 1] = 0;   // No money if starting from house n-1 (out of bound)

    // Base cases for dp2 (1 to n-1)
    dp2[n] = 0;       // No money if starting from house n
    dp2[n + 1] = 0;   // Padding for boundary condition

    // Fill dp1 backwards from house n-2 to 0
    for(int i = n - 2; i >= 0; i--)
        dp1[i] = max((nums[i] + dp1[i + 2]), dp1[i + 1]);

    // Fill dp2 backwards from house n-1 to 1
    for(int i = n - 1; i >= 1; i--)
        dp2[i] = max((nums[i] + dp2[i + 2]), dp2[i + 1]);

    // Print both computed results (optional/debugging)
    cout << dp1[0] << " " <<dp2[1] << endl;

    // Return the max between both strategies
    return max(dp1[0], dp2[1]);
}

// Method 3 - Bottom Up with Space Optimization - O(N), O(1)
int rob3(vector<int> &nums){

    // Get total number of houses
    int n = nums.size();

    // If only one house, return its value
    if(n == 1) return nums[0];

    // Variables to store final results of both strategies
    int result1, result2;

    // First and second keep track of max loot for 0 to n-2
    int first = 0, second = 0;

    // Process houses from n-2 to 0 (excluding last house)
    for(int i = n - 2; i >= 0; i--){

        // result1 stores the best of robbing current or skipping
        result1 = max((nums[i] + second), first);
        // Update second and first for next iteration
        second = first;
        first = result1;
    }

    // Reset values for second strategy (excluding first house)
    first = 0;
    second = 0;

    // Process houses from n-1 to 1
    for(int i = n - 1; i >= 1; i--){

        // result2 stores the best of robbing current or skipping
        result2 = max((nums[i] + second), first);
        // Update second and first
        second = first;
        first = result2;
    }

    // Return max of both strategies
    return max(result1, result2);
}


int main(){

    vector<int> nums = {1,2,3};

    cout << rob3(nums);

}