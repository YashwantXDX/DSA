#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

*/

// Recusive Way
int find1(int i, int W, vector<int> &wt, vector<int> &val){

    if(W == 0) return 0;

    if(i == 0) return 0;

    if(wt[i - 1] > W)
        return find1(i - 1, W, wt, val);
    
    else
        return max(val[i - 1] + find1(i - 1, W - wt[i - 1], wt, val), find1(i - 1, W, wt, val));

}

int knapsack1(int W, vector<int> &val, vector<int> &wt) {
    
    int n = val.size();

    return find1(n, W, wt, val);
    
}

// Top Down Dynamic Programming Solution to solve 0/1 Knapsack with memoization
int find2(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){

    // Base case: If remaining capacity is 0, no more value can be added
    if(W == 0) return 0;

    // Base case: If no items left to consider, return 0
    if(i == 0) return 0;

    // If subproblem already solved, return the stored result
    if(dp[i][W] != -1)
        return dp[i][W];

    // If the current item's weight is more than remaining capacity
    // we cannot include it, so skip it
    if(wt[i - 1] > W)
        return dp[i][W] = find2(i - 1, W, wt, val, dp);

    else
        // Two choices:
        // 1. Include the current item → add its value and reduce capacity
        // 2. Exclude the current item → skip to previous item with same capacity
        return dp[i][W] = max(
            val[i - 1] + find2(i - 1, W - wt[i - 1], wt, val, dp),
            find2(i - 1, W, wt, val, dp)
        );
}

// Main function to initialize and call the knapsack helper
int knapsack2(int W, vector<int> &val, vector<int> &wt) {
    
    // Number of items
    int n = val.size();

    // Create a 2D DP table of size (n+1) x (W+1), initialized to -1
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));

    // Call recursive function starting from all items and full capacity
    return find2(n, W, wt, val, dp);
}

// Bottom-Up Dynamic Programming solution for 0/1 Knapsack
int knapsack3(int W, vector<int> &val, vector<int> &wt){

    // Number of items
    int n = val.size();

    // Create a 2D dp table of size (n+1) x (W+1), initialized to 0
    // dp[i][j] = maximum value with first i items and capacity j
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));

    // Fill the dp table row by row
    for(int i = 1; i <= n; i++){ // i = current item
        for(int j = 1; j <= W; j++){ // j = current capacity

            // If the weight of current item is more than current capacity
            // We cannot include the item, so we carry forward the previous value
            if(wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                // Otherwise, we take the maximum of:
                // 1. Including the current item → add its value and reduce weight
                // 2. Excluding the current item → take value from above row
                dp[i][j] = max(
                    val[i - 1] + dp[i - 1][j - wt[i - 1]], // include
                    dp[i - 1][j]                            // exclude
                );
        }
    }

    // Return the maximum value that can be achieved with all items and full capacity
    return dp[n][W];
}

// Space-Optimized Bottom-Up Dynamic Programming solution for 0/1 Knapsack
int knapsack4(int W, vector<int> &val, vector<int> &wt){

    // Number of items
    int n = val.size();

    // Create a 1D dp array of size (W + 1), initialized to 0
    // dp[j] = max value for capacity j
    vector<int> dp(W + 1, 0);

    // Loop through each item
    for(int i = 0; i < n; i++){

        // Loop through capacities from W down to wt[i]
        // (going backward ensures we don't reuse the same item)
        for(int j = W; j >= wt[i]; j--){

            // Either take the item or leave it
            // Take: val[i] + dp[j - wt[i]]
            // Leave: dp[j]
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }

    // Final result: max value for full capacity W
    return dp[W];
}


int main(){

    int W = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3};

    cout << knapsack4(W, val, wt);

}