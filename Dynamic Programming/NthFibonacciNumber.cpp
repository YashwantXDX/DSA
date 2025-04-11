#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

    Why Memoization Works:
    Without memoization, recursive Fibonacci is exponential (O(2^n)) because it recomputes values many times.

    With memoization, each value from 0 to n is computed only once → Time Complexity: O(n).


*/

// Top Down Approach + Memorization

// Recursive function to find the nth Fibonacci number using memoization
int find(int n, vector<int> &dp) {

    // Base case: fib(0) = 0, fib(1) = 1
    if(n <= 1)
        return n;

    // If already calculated, return stored result
    if(dp[n] != -1)
        return dp[n];

    // Recursively calculate and store the result in dp[n]
    // This saves time by avoiding repeated work
    return dp[n] = find(n - 1, dp) + find(n - 2, dp);
}

// Main function to return nth Fibonacci number
int nthFibonacci1(int n) {

    // Initialize a dp array of size (n + 1) with -1
    vector<int> dp(n + 1, -1);

    // Optional: base cases explicitly initialized
    dp[0] = 0;
    dp[1] = 1;

    // Start the recursive calculation
    return find(n, dp);
}

// Function to return the nth Fibonacci number using bottom-up DP
int nthFibonacci2(int n) {

    // Create a dp array to store Fibonacci values up to n
    vector<int> dp(n + 1, -1);

    // Base cases
    dp[0] = 0; // 0th Fibonacci number
    dp[1] = 1; // 1st Fibonacci number

    // Fill the dp array from 2 to n
    for(int i = 2; i <= n; i++) {
        // Each Fibonacci number is the sum of the previous two
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}


int main(){

    int n = 20;

    cout << nthFibonacci2(n);

}