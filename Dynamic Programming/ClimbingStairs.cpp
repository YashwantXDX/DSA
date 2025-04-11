#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/climbing-stairs/description/

    Why Memoization Works:
    Without memoization, recursive Fibonacci is exponential (O(2^n)) because it recomputes values many times.

    With memoization, each value from 0 to n is computed only once → Time Complexity: O(n).


*/

// Top Down Approach

// Recursive function with memoization
int find(int n, vector<int> &dp) {
    // Base cases: 1 way to climb 0 or 1 steps
    if(n <= 2)
        return n;

    // If already computed, return cached value
    if(dp[n] != -1)
        return dp[n];

    // Save the result of current subproblem
    return dp[n] = find(n - 1, dp) + find(n - 2, dp);
}

// Main function using top-down DP
int climbStairs1(int n) {
    // Create dp array and initialize with -1
    vector<int> dp(n + 1, -1);

    return find(n, dp);
}


// Bottom Up Approach
// Iterative DP using tabulation
int climbStairs2(int n) {

    // Base case: only 1 way to reach step 0 or 1
    if(n <= 1) return 1;

    // dp[i] represents number of ways to reach step i
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    // Fill the dp table from 2 to n
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}


// Space Soptimized Approach
// Uses only O(1) space
int climbStairs3(int n) {

    // first = dp[i + 1], second = dp[i + 2]
    int first = 1;
    int second = 0;
    int result;

    // Start from the end and move backward
    for(int i = n - 1; i >= 0; i--) {

        // dp[i] = dp[i+1] + dp[i+2]
        result = first + second;

        // Shift values for next iteration
        second = first;
        first = result;
    }

    return result;
}


int main(){

    int n = 8;

    cout << climbStairs3(n);

}