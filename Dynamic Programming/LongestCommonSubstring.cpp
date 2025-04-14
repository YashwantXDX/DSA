#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/

// Pure Recursion - TLE (Time Limit Exceeded) due to overlapping subproblems
int find(int n, int m, string &s1, string &s2, int &ans) {
    
    // If either string becomes empty, no further substring can be found
    if(n == 0 || m == 0) return 0;
    
    // Variable to store the length of current matching substring
    int currentLen = 0;
    
    // If the current characters in both strings match
    if(s1[n - 1] == s2[m - 1]) {
        
        // Extend the current substring by 1 and recurse on previous characters
        currentLen = 1 + find(n - 1, m - 1, s1, s2, ans);
        
        // Update the overall maximum length found so far
        ans = max(ans, currentLen);
    }
    
    // Explore other possibilities by skipping one character from either string
    find(n - 1, m, s1, s2, ans);
    find(n, m - 1, s1, s2, ans);
    
    // Return the current length to the previous call
    return currentLen;
}

// Function to initiate the recursive search for longest common substring
int longestCommonSubstr(string& s1, string& s2) {
    
    // Initialize the answer (maximum length found)
    int ans = 0;
    
    // Get lengths of both input strings
    int n = s1.size();
    int m = s2.size();
    
    // Call the recursive helper function
    find(n, m, s1, s2, ans);
    
    // Return the final answer
    return ans;
}

// Top Down Approach - O(N * M), O(N * M)
// Recursive function with memoization to find the longest common substring
int findd(int n, int m, string &s1, string &s2, int &ans, vector<vector<int>> &dp) {
    
    // Base case: if either string is empty, return 0 (no more common substring possible)
    if(n == 0 || m == 0) return 0;
    
    // If this subproblem has already been solved, return the cached result
    if(dp[n][m] != -1) return dp[n][m];
    
    // Variable to store the current matching substring length
    int currentLen = 0;
    
    // If characters at current positions match
    if(s1[n - 1] == s2[m - 1]) {
        
        // Extend the current matching substring
        currentLen = 1 + findd(n - 1, m - 1, s1, s2, ans, dp);
        
        // Update the overall maximum length found so far
        ans = max(ans, currentLen);
    }
    
    // Explore other paths by skipping one character from either string
    findd(n - 1, m, s1, s2, ans, dp);
    findd(n, m - 1, s1, s2, ans, dp);
    
    // Memoize and return the current length
    return dp[n][m] = currentLen;
}

// Main function to initiate the longest common substring search
int longestCommonSubstr2(string& s1, string& s2) {
    
    // Initialize the result variable to store the maximum length
    int ans = 0;
    
    // Get the lengths of both strings
    int n = s1.size();
    int m = s2.size();
    
    // Create a 2D DP table and initialize all values to -1 for memoization
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    
    // Call the recursive function to compute the result
    findd(n, m, s1, s2, ans, dp);
    
    // Return the final answer
    return ans;
}

// Bottom Up Approach - O(N * M), O(N * M)
// Function to find the length of the longest common substring using bottom-up DP
int longestCommonSubstr3(string& s1, string& s2) {
    
    // Variable to store the maximum length of common substring found so far
    int ans = 0;
    
    // Get the lengths of the two strings
    int n = s1.size();
    int m = s2.size();
    
    // Create a 2D DP table of size (n+1) x (m+1) initialized with 0
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    // Iterate through each character of s1
    for(int i = 1; i <= n; i++) {
        // Iterate through each character of s2
        for(int j = 1; j <= m; j++) {
            
            // If characters match, extend the common substring
            if(s1[i - 1] == s2[j - 1]) {
                
                // Increase length by 1 from the diagonal cell (previous characters)
                dp[i][j] = 1 + dp[i - 1][j - 1];
                
                // Update the answer if we found a longer substring
                ans = max(ans, dp[i][j]);
            }
            // No 'else' part needed because if characters don't match, dp[i][j] remains 0
        }
    }
    
    // Return the maximum length of the common substring
    return ans;
}

// Space Optimized Approach - O(N * M), O(N)
// Function to find the length of the longest common substring using space optimization
int longestCommonSubstr4(string& s1, string& s2) {
    
    // Variable to store the final answer (maximum length found)
    int ans = 0;
    
    // Get the lengths of both input strings
    int n = s1.size();
    int m = s2.size();
    
    // Create a 1D DP array to store current values for each column (s2)
    vector<int> dp(m + 1, 0);
    
    // Variables to track current and previous diagonal values
    int current, prev;
    
    // Loop through each character in the first string
    for(int i = 1; i <= n; i++) {
        
        // Reset the previous diagonal value at the start of each row
        prev = 0;
        
        // Loop through each character in the second string
        for(int j = 1; j <= m; j++) {
            
            // Save current dp[j] before updating, to use as 'prev' for next diagonal
            current = dp[j];
            
            // If characters match, increase length from the diagonal cell (prev)
            if(s1[i - 1] == s2[j - 1]) {
                dp[j] = 1 + prev;         // Match found, update with 1 + previous diagonal value
                ans = max(ans, dp[j]);    // Update maximum length found
            }
            
            // If characters don't match, reset current dp[j] to 0
            else
                dp[j] = 0;
            
            // Update prev for the next iteration (diagonal for next cell)
            prev = current;
        }
    }
    
    // Return the length of the longest common substring
    return ans;
}


int main(){

    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << longestCommonSubstr(s1, s2);

}