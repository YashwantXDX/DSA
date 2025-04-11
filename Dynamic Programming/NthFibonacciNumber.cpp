#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

    Why Memoization Works:
    Without memoization, recursive Fibonacci is exponential (O(2^n)) because it recomputes values many times.

    With memoization, each value from 0 to n is computed only once → Time Complexity: O(n).


*/

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
int nthFibonacci(int n) {

    // Initialize a dp array of size (n + 1) with -1
    vector<int> dp(n + 1, -1);

    // Optional: base cases explicitly initialized
    dp[0] = 0;
    dp[1] = 1;

    // Start the recursive calculation
    return find(n, dp);
}


int main(){

    int n = 20;

    cout << nthFibonacci(n);

}