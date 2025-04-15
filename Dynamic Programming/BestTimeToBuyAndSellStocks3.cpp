#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

    
*/

// Top Down Approach
// Recursive helper function to calculate max profit
// day: current day index
// trans: number of transactions left (at most 2)
// buy: whether we are allowed to buy (1) or we have to sell (0)
// n: total number of days
// prices: array of stock prices
// dp: 3D memoization table to store intermediate results
int find(int day, int trans, int buy, int n, vector<int>& prices, vector<vector<vector<int>>> &dp){

    // Base case: if no transactions left or no days left, profit is 0
    if(trans == 0 || day == n)
        return 0;

    // If this state has already been computed, return its value
    if(dp[day][trans][buy] != -1) return dp[day][trans][buy];

    // If we are allowed to buy
    if(buy){
        // Two choices:
        // 1. Buy the stock today (-prices[day]) and move to next day with buy = 0 (can't buy again until we sell)
        // 2. Skip buying today, move to next day with buy = 1
        return dp[day][trans][buy] = max(
            -prices[day] + find(day + 1, trans, 0, n, prices, dp), 
            find(day + 1, trans, 1, n, prices, dp)
        );
    }
    else {
        // If we must sell (we already bought):
        // Two choices:
        // 1. Sell the stock today (+prices[day]) and move to next day with one transaction used and buy = 1
        // 2. Skip selling today, move to next day with same state
        return dp[day][trans][buy] = max(
            prices[day] + find(day + 1, trans - 1, 1, n, prices, dp), 
            find(day + 1, trans, 0, n, prices, dp)
        );
    }
}

// Main function to calculate the max profit with at most 2 transactions
int maxProfit(vector<int>& prices) {
    int n = prices.size(); // Total number of days

    // Create a 3D DP table: dp[day][transactions_left][buy/sell]
    // Initialize all values with -1 (uncomputed state)
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2 + 1, vector<int> (2, -1)));

    // Start from day 0, with 2 transactions allowed, and the ability to buy
    return find(0, 2, 1, n, prices, dp);
}


// Time Optimized Version - O(N)
int maxProfit(vector<int>& prices) {
    
    int n = prices.size(); // Get the number of days

    // Create a 2D DP table:
    // dp[i][j] represents the max profit using at most i transactions until day j
    vector<vector<int>> dp(2 + 1, vector<int> (n + 1, 0));

    int total; // Temporary variable to store the best balance for buying

    // Loop through number of allowed transactions (1 to 2)
    for(int i = 1; i <= 2; i++) {

        // Initialize 'total' to the negative of the first day's price
        // This represents buying the stock on day 0
        total = -prices[0];

        // Loop through days starting from day 2 (index 1-based in DP table)
        for(int j = 2; j <= n; j++) {

            // Either:
            // 1. We don't trade today and carry forward yesterday's profit: dp[i][j - 1]
            // 2. We sell today: prices[j - 1] + total
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + total);

            // Update 'total' to consider the best scenario to buy in the past with one less transaction
            // This allows buying at the best time to maximize future profit
            total = max(total, -prices[j - 1] + dp[i - 1][j]);
        }
    }

    // The maximum profit with 2 transactions until day n
    return dp[2][n];
}


int main(){

    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << maxProfit(prices);

}