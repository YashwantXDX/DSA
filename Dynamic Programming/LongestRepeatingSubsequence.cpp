#include<bits/stdc++.h>
using namespace std;

/*    

    Problem Link :- https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/

// Pure Recursion
int find(int n, int m, string &str){
    
    // If any of the index goes 0 then return 0
    if(n == 0 || m == 0) return 0;
    
    // If Got same index then max of (skip the current value of s1, skip the current value of s2)
    if(n == m)
        return max(find(n - 1, m, str), find(n, m - 1, str));
    
    // We got different index and value same then add 1
    else if(str[n - 1] == str[m - 1])
        return 1 + find(n - 1, m - 1, str);
    
    // Else Continue the journey
    else
        return max(find(n - 1, m, str), find(n, m - 1, str));
    
}

int LongestRepeatingSubsequence1(string &s) {
    
    int n = s.size();
    
    return find(n, n, s);
    
}

// Top Down Approach
// Function to find the length of the longest repeating subsequence
int findd(int n, int m, string &str, vector<vector<int>> &dp){
        
    // Base case: if either string is empty, there's no common subsequence
    if(n == 0 || m == 0) return 0;
    
    // If the result for this subproblem is already calculated, return it
    if(dp[n][m] != -1) return dp[n][m];
        
    // If we are at the same index in the string, skip this pair (to avoid matching same character with itself)
    if(n == m)
        return dp[n][m] = max(findd(n - 1, m, str, dp), findd(n, m - 1, str, dp));
    
    // If characters match and are from different positions, include it in the result
    else if(str[n - 1] == str[m - 1])
        return dp[n][m] = 1 + findd(n - 1, m - 1, str, dp);
    
    // If characters don't match, take the maximum of skipping one character from either string
    else
        return dp[n][m] = max(findd(n - 1, m, str, dp), findd(n, m - 1, str, dp));
}

// Main function to be called to find the longest repeating subsequence in a string
int LongestRepeatingSubsequence2(string &s) {
    
    // Get the length of the string
    int n = s.size();
    
    // Initialize a 2D DP table of size (n+1) x (n+1) with all values as -1
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    
    // Call the recursive function with full length of the string for both indices
    return findd(n, n, s, dp);
}

// Bottom Up Approach
// Function to find the length of the longest repeating subsequence using dynamic programming
int LongestRepeatingSubsequence3(string &s) {
    
    // Get the length of the input string
    int n = s.size();
    
    // Create a 2D DP table of size (n+1) x (n+1) and initialize all values to 0
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    
    // Loop through each character of the string as the first index
    for(int i = 1; i <= n; i++){
        // Loop through each character of the string as the second index
        for(int j = 1; j <= n; j++){
            
            // If the characters match but the indices are not the same
            if(i == j || s[i - 1] != s[j - 1])
                // Take the maximum value by either excluding the ith or jth character
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            
            else
                // If characters match and indices are different, add 1 to the result
                dp[i][j] = 1 + dp[i - 1][j - 1];
        }
    }
    
    // The bottom-right cell contains the length of the longest repeating subsequence
    return dp[n][n];
}


int main(){

    string s1 = "axxzxy";

    cout << LongestRepeatingSubsequence3(s1);

}