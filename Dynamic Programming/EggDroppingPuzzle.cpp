#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1


    
*/

// Top Down Approach - TLE - O(N * K^2)
// Recursive function to find the minimum number of attempts needed
int find(int eggs, int floors, vector<vector<int>> &dp){
    
    // If only one egg left, we need to try all floors from 1 to 'floors'
    if(eggs == 1) return floors;

    // If there are no floors, no trials needed
    if(floors == 0) return 0;

    // If we've already solved this subproblem, return the answer
    if(dp[eggs][floors] != -1) return dp[eggs][floors];

    int ans = INT_MAX; // Initialize answer to a very large number
    int temp;

    // Try dropping the egg from every floor from 1 to 'floors'
    for(int i = 1; i <= floors; i++){
        
        // Two cases:
        // 1. Egg breaks → check below floors with one less egg
        // 2. Egg doesn't break → check above floors with same eggs
        // We take the worst-case (max) because we want to **guarantee** minimum attempts
        temp = 1 + max(find(eggs - 1, i - 1, dp), find(eggs, floors - i, dp));
        
        // Choose the minimum among all attempts
        ans = min(ans, temp);
    }

    // Store and return the result
    return dp[eggs][floors] = ans;
}

// Main function to start the recursion
int eggDrop(int n, int k) {

    // Create a DP table initialized with -1 for memoization
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));

    // Start the recursive function with n eggs and k floors
    return find(n, k, dp);
}


// Bottom Up Approch - TLE - O(N * K^2)
int eggDrop2(int n, int k) {

    // Create a DP table with (n+1) eggs and (k+1) floors
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

    // Base case: if there's only 1 egg, we need j tries for j floors
    for(int i = 0; i <= k; i++)
        dp[1][i] = i;

    // Build the table for more than 1 egg
    for(int i = 2; i <= n; i++) { // Loop over eggs

        for(int j = 1; j <= k; j++) { // Loop over floors

            int ans = INT_MAX;
            int temp;

            // Try dropping from each floor x
            for(int x = 1; x <= j; x++) {

                // Take the worst case between egg breaking and not breaking
                temp = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);

                // Choose the minimum among all floors
                ans = min(ans, temp);
            }

            // Store the result
            dp[i][j] = ans;
        }
    }

    // Final result for n eggs and k floors
    return dp[n][k];
}

// Bottom Up - O(N * K * log K) - OPTIMISED
int eggDrop(int n, int k) {

    // Create a DP table: dp[eggs][floors]
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: With 1 egg, we need 'j' trials for 'j' floors
    for (int j = 1; j <= k; ++j)
        dp[1][j] = j;

    // Build the table from 2 eggs up to n eggs
    for (int eggs = 2; eggs <= n; ++eggs) {

        for (int floors = 1; floors <= k; ++floors) {

            int low = 1, high = floors;
            int ans = INT_MAX;

            // Binary search to minimize worst-case attempts
            while (low <= high) {
                int mid = (low + high) / 2;

                // Two cases:
                int breakEgg = dp[eggs - 1][mid - 1];     // Egg breaks, check below
                int notBreakEgg = dp[eggs][floors - mid]; // Egg doesn't break, check above
                int temp = 1 + max(breakEgg, notBreakEgg); // Take worst case

                ans = min(ans, temp); // Keep the minimum of the worst cases

                // Move binary search boundaries
                if (breakEgg > notBreakEgg)
                    high = mid - 1; // Move left: try smaller floor
                else
                    low = mid + 1;  // Move right: try higher floor
            }

            dp[eggs][floors] = ans;
        }
    }

    // Final answer for n eggs and k floors
    return dp[n][k];
}

int main(){

    int n = 2;
    int k = 36;

    cout << eggDrop(n, k);

}