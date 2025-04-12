#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

*/

// Simplest Mathematical Step
// Function to return the number of distinct ways to reach the nth stair
// when you can climb either 1 or 2 stairs at a time, 
// but cannot take two 2-steps in a row
int nthStair1(int n) {

    // The total number of valid ways to reach the nth stair,
    // without taking two 2-steps consecutively, is always (n / 2) + 1.
    // Why?
    // Because for each valid combination, we can take 0 to (n / 2) two-steps,
    // and fill the rest with one-steps in a non-repeating two-step pattern.
    return 1 + n / 2;

}

// Top Down Approach

// Recursive function with memoization to count the number of ways to reach the nth stair
// using steps defined in the 'step' array (here, 1 and 2), without consecutive 2-steps
int find(int i, int n, vector<int> &step, vector<vector<int>> &dp){

    // Base case: If no stairs left to climb, that's one valid way
    if(n == 0) return 1;

    // If no steps left to try, and stairs are still left, return 0 (invalid way)
    if(i == 0) return 0;

    // If this subproblem is already solved, return the stored result
    if(dp[i][n] != -1) return dp[i][n];

    // If the current step size is greater than the remaining stairs,
    // we cannot take this step, move to smaller steps (i - 1)
    if(step[i - 1] > n)
        return dp[i][n] = find(i - 1 , n, step, dp);

    else
        // Two choices:
        // 1. Take current step → reduce remaining stairs by step size
        // 2. Skip current step and move to smaller step
        return dp[i][n] = find(i , n - step[i - 1], step, dp) + find(i - 1 , n, step, dp);
}

// Main function to calculate number of ways to climb nth stair
int nthStair2(int n){
    
    // Allowed steps: 1-step and 2-step
    vector<int> step = {1 , 2};

    // Get the largest step value (in this case 2)
    int index = step[step.size() - 1];

    // Create a 2D dp array of size (steps) x (n+1), initialized with -1
    vector<vector<int>> dp(index + 1, vector<int> (n + 1, -1));

    // Start recursion from the last index (2 steps allowed), and full stair count
    return find(2, n, step, dp);
}

// Bottom-Up Dynamic Programming solution to count the number of ways
// to climb the nth stair using 1 or 2 steps, without taking two 2-steps in a row
int nthStair3(int n){

    // Allowed step sizes: 1 and 2
    vector<int> step = {1, 2};

    // Create a 2D dp table of size 3 x (n+1), initialized with 0
    // dp[i][j] represents the number of ways to reach stair j using first i types of steps
    vector<vector<int>> dp(3, vector<int> (n + 1, 0));

    // Base case: There is always 1 way to reach stair 0 — by doing nothing
    for(int i = 0; i < 3; i++)
        dp[i][0] = 1;

    // Fill the DP table
    for(int i = 1; i <= 2; i++){ // Loop through each step type (1-step, 2-step)
        for(int j = 1; j <= n; j++){ // Loop through stair numbers from 1 to n

            // If current step is larger than j, we cannot use it
            // So, copy the value from previous step type
            if(step[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            // Otherwise:
            // 1. Use the current step → stay at same i, subtract step size from j
            // 2. Don't use current step → move to previous step type
            else
                dp[i][j] = dp[i][j - step[i - 1]] + dp[i - 1][j];
        }
    }

    // Return the number of ways to reach stair n using both 1 and 2 steps
    return dp[2][n];
}

// Space-Optimized DP solution to count ways to reach the nth stair
// using steps of 1 or 2, without consecutive 2-steps
int nthStair4(int n) {

    // Allowed step sizes
    vector<int> step = {1, 2};

    // Create a 1D dp array of size n+1, initialized to 0
    // dp[j] = number of ways to reach stair j
    vector<int> dp(n + 1, 0);

    // Base case: 1 way to reach stair 0 (by doing nothing)
    dp[0] = 1;

    // Loop through each type of step
    for (int i = 0; i < step.size(); i++) {
        // Update dp array for all stair values from step[i] to n
        for (int j = step[i]; j <= n; j++) {

            // Add the number of ways to reach (j - step[i]) to dp[j]
            // This simulates using the current step at position j
            dp[j] += dp[j - step[i]];
        }
    }

    // Return number of ways to reach stair n
    return dp[n];
}



int main(){

    int n = 4;

    cout << nthStair4(n);

}