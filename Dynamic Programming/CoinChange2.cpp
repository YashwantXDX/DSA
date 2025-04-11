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

int find(int index, int amount, vector<int> &coins, int n, vector<vector<int>> &dp){

    if(amount == 0) return 1;

    if(amount < 0 || index >= n) return 0;

    if(dp[index][amount] != -1) return dp[index][amount];

    // Use Coin + No Coin Use
    return dp[index][amount] = find(index, amount - coins[index], coins, n, dp) + find(index + 1, amount, coins, n, dp);

}

// Method 1 - Top Down Approach - O(N), O(N)
int change1(int amount, vector<int>& coins) {
    
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));

    return find(0, amount, coins, n, dp);

}


int main(){

    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change1(amount, coins);

}