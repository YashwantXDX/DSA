#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/coin-change-ii/description/

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

*/

// Recursive helper function to count combinations that sum up to 'amount'
int find(int index, int amount, vector<int> &coins, int n, vector<vector<int>> &dp){

    // Base case: If amount becomes 0, we found a valid combination
    if(amount == 0) return 1;

    // If amount becomes negative or we’ve checked all coins, no valid combination
    if(amount < 0 || index >= n) return 0;

    // If the current subproblem is already solved, return its stored value
    if(dp[index][amount] != -1) return dp[index][amount];

    // Recursive case:
    // 1. Include current coin: stay at same index, reduce amount
    // 2. Exclude current coin: move to next index, keep amount same
    return dp[index][amount] = find(index, amount - coins[index], coins, n, dp) + find(index + 1, amount, coins, n, dp);
}

// Method 1 - Top Down Dynamic Programming with Memoization - Time: O(N * Amount), Space: O(N * Amount)
int change1(int amount, vector<int>& coins) {
    
    // Get number of different coin denominations
    int n = coins.size();

    // Create a 2D dp array initialized with -1 for memoization
    // dp[i][j] = number of ways to make amount j using coins from index i
    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));

    // Start the recursion from index 0 with the full amount
    return find(0, amount, coins, n, dp);
}

// Bottom-Up Dynamic Programming approach to count ways to make change
int change2(int amount, vector<int> &coins){

    // Get number of different coin types
    int n = coins.size();

    // Create a 2D DP table of size (n+1) x (amount+1) initialized with 0
    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));

    // Base case: There's always 1 way to make amount 0 — by choosing no coins
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill the rest of the DP table
    for(int i = 1; i <= n; i++){ // Loop through each coin
        for(int j = 1; j <= amount; j++){ // Loop through all target amounts

            // If the current coin's value is more than the current amount j,
            // we cannot use this coin, so carry the value from the previous row
            if(coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            // Else, consider two choices:
            // 1. Use the current coin → stay on same row, subtract coin value from j
            // 2. Don’t use the coin → take value from the row above
            else
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        }
    }

    // Return the number of ways to make up the given amount using all coins
    return dp[n][amount];
}


int main(){

    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change2(amount, coins);

}