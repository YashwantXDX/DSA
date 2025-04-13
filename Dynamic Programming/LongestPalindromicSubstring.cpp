#include<bits/stdc++.h>
using namespace std;

/*

    This Question is Same as Longest Common Subsequence

    Just take a string and reverse it and all the code is same as Longest Common Subsequence.
    

    Problem Link :- https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/

// Top Down Approach - O(N * M), O(N * M)
// Recursive helper function to find LCS length with memoization
int findd(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){

    // Base case: If either string is empty, LCS is 0
    if(n == 0 || m == 0) return 0;

    // If value already computed, return from dp
    if(dp[n][m] != -1) return dp[n][m];

    // If last characters match, include them and move diagonally
    if(s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + findd(n - 1, m - 1, s1, s2, dp);

    else
        // If characters don't match, take max of:
        // 1. Move left in s2
        // 2. Move up in s1
        return dp[n][m] = max(findd(n, m - 1, s1, s2, dp), findd(n - 1, m, s1, s2, dp));
}

int longestPalinSubseq1(string &s1) {
    
    // Copy the string 1 to string 2
    // reverse the string 2
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    // Get lengths of both strings
    int m = s2.size();
    int n = s1.size();

    // Create a 2D dp table initialized with -1 for memoization
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

    // Call the recursive function with full lengths
    return findd(n, m, s1, s2, dp);

}

// Bottom Up Approach - O(N * M), O(N * M)
int longestPalinSubseq2(string &s1){

    // Copy the string 1 to string 2
    // reverse the string 2
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    
    // Get lengths of both strings
    int n = s1.size();
    int m = s2.size();

    // Create a 2D dp table of size (n+1) x (m+1), initialized to 0
    // dp[i][j] represents the length of LCS of s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    // Fill the dp table row by row
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            // If characters match, include it in LCS length
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            
            // Else, take the maximum of excluding either character
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // Final answer: LCS of full strings is in dp[n][m]
    return dp[n][m];

}

// Space Optimized - O(N * M), O(N)
int longestPalinSubseq3(string &s1){
    
    // Copy the string 1 to string 2
    // reverse the string 2
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    
    int n = s1.size(); // Length of first string
    int m = s2.size(); // Length of second string

    // Single row DP array for storing previous results (1D instead of 2D)
    vector<int> dp(m + 1, 0);

    int current, prev;

    // Loop through each character of s1
    for(int i = 1; i <= n; i++) {

        // Initialize current and prev for each row
        current = prev = 0;

        // Loop through each character of s2
        for(int j = 1; j <= m; j++) {

            // Save the top-left (dp[i-1][j-1]) value before overwriting
            prev = current;

            // Save current dp[j] (dp[i-1][j]) before updating
            current = dp[j]; 

            // If characters match, add 1 to the diagonal previous result
            if(s1[i - 1] == s2[j - 1])
                dp[j] = 1 + prev;

            // Else take the max from left (dp[j - 1]) or top (previous dp[j])
            else
                dp[j] = max(dp[j], dp[j - 1]);
        }
    }

    // Final result is stored in dp[m] (end of the row)
    return dp[m];

}

int main(){

    string s1 = "bbabcbcab";

    cout << longestPalinSubseq3(s1);

}