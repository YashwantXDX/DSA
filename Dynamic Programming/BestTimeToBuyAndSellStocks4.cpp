#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

    Same code and Best Time to buy and sell stock 3

    but change all the 2 with k

    Also Try Top Down and Bottom Up Approach
    
*/

int maxProfit(int k, vector<int>& prices) {
    
    int n = prices.size(); // Get the number of days

    // Create a DP table with dimensions (k+1) x (n+1)
    // dp[i][j] represents the max profit with at most i transactions until day j
    vector<vector<int>> dp(k + 1, vector<int> (n + 1, 0));

    int total; // Used to keep track of the best buying option

    // Loop through the number of transactions from 1 to k
    for(int i = 1; i <= k; i++) {

        // Initialize total as if we bought the stock on day 0
        total = -prices[0];

        // Loop through days from day 2 to n
        for(int j = 2; j <= n; j++) {

            // Either:
            // 1. Don't trade on day j, so carry forward the profit from day j-1
            // 2. Sell on day j, and add it to the best previous buy (tracked by 'total')
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + total);

            // Update total to reflect the best buying opportunity:
            // max of previous total OR buying at today's price with i-1 transactions used
            total = max(total, -prices[j - 1] + dp[i - 1][j]);
        }
    }

    // Return the maximum profit achievable with at most k transactions until day n
    return dp[k][n];
}


int main(){

    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;

    cout << maxProfit(k, prices);

}