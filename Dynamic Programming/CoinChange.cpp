#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

*/

// Pure Recursive Way - Test Cases Pass - 1110 / 1111
// Last one was for DP
int find(int i, int sum, vector<int> &coins){
        
    if(sum == 0) return 1;
    
    if(i == 0) return 0;
    
    // Skip that iteration if sum less than coin [i]
    if(sum < coins[i - 1]) 
        return find(i - 1, sum, coins);
    
    // Now Take + Leave
    else
        return find(i, sum - coins[i - 1], coins) + find(i - 1, sum, coins);
}

int count1(vector<int>& coins, int sum) {
    
    int n = coins.size();
    
    return find(n, sum, coins);
    
}

// Top Down Approach
// Recursive function to count number of ways to make 'sum' using first 'i' coins
int findd(int i, int sum, vector<int> &coins, vector<vector<int>> &dp){
        
    // Base case: if sum becomes 0, we found a valid way
    if(sum == 0) return 1;

    // Base case: no coins left and sum is not zero => no valid way
    if(i == 0) return 0;

    // If this subproblem is already solved, return the stored result
    if(dp[i][sum] != -1) return dp[i][sum];

    // If current coin is greater than remaining sum, skip it
    if(sum < coins[i - 1]) 
        return dp[i][sum] = findd(i - 1, sum, coins, dp);
    
    // Otherwise, we have two options:
    // 1. Include the current coin → reduce sum, keep same coin (unbounded use)
    // 2. Exclude the current coin → move to previous coin
    return dp[i][sum] = findd(i, sum - coins[i - 1], coins, dp) + findd(i - 1, sum, coins, dp);
}

// Main function to initialize dp and start recursion
int count2(vector<int>& coins, int sum) {
    
    // Number of coins
    int n = coins.size();

    // Initialize dp table with -1 for memoization (size: (n+1) x (sum+1))
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));

    // Start recursion from all coins and given sum
    return findd(n, sum, coins, dp);
}

// Bottom-Up DP to count combinations to make 'sum' using given coins
int count3(vector<int>& coins, int sum){

    // Total number of coins
    int n = coins.size();

    // Create a 2D dp array with dimensions (n+1) x (sum+1), initialized to 0
    // dp[i][j] = number of ways to make sum j using first i coins
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));

    // Base case: There is 1 way to make sum = 0 (by choosing no coins)
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill the dp table
    for(int i = 1; i <= n; i++){ // loop through coins
        for(int j = 1; j <= sum; j++){ // loop through all sums from 1 to target

            // If the current coin is larger than the sum we want,
            // we cannot include it → so copy the value from the previous row
            if(j < coins[i - 1]) 
                dp[i][j] = dp[i - 1][j];
            
            else
                // Otherwise, we take the sum of:
                // 1. Including the current coin → stay at same row, reduce the sum
                // 2. Excluding the current coin → move to previous row
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        }
    }

    // Final answer is in dp[n][sum]
    return dp[n][sum];
}

// Space Optimization
// Space-Optimized Bottom-Up DP to count combinations to make 'sum' using given coins
int count4(vector<int> &coins, int sum){

    // Number of coin types
    int n = coins.size();

    // Create a 1D dp array where dp[j] stores number of ways to make sum j
    vector<int> dp(sum + 1, 0);

    // Base case: There is one way to make sum = 0 (by choosing no coins)
    dp[0] = 1;

    // Loop through each coin
    for(int i = 1; i <= n; i++) {

        // For each coin, update the dp array from coin value to sum
        for(int j = coins[i - 1]; j <= sum; j++) {

            // If we include the current coin, add the number of ways to make (j - coin)
            dp[j] += dp[j - coins[i - 1]];
        }
    }

    // Final answer: number of ways to make the given sum
    return dp[sum];
}


int main(){

    vector<int> coins = {1,2,3};
    int sum = 4;

    cout << count4(coins, sum);

}