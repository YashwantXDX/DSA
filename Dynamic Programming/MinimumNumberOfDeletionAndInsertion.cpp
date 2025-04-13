#include<bits/stdc++.h>
using namespace std;

/*    

    Problem Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/

// Direct Space Optimized Solution as it is same as Longest Common Subsequence

// This is Same as LCS (Longest Common Subsequence)
// Hume bas LCS nikaalna hai dono string me orr uska jo answer aayega
// use hume deletion ke liye s1.size() - lcs krna pdega
// Orr Insertion ke liye s2.size() - lcs krna pdega
// and dono ka sum kar ke return
// Function to calculate the minimum number of operations to make two strings equal
// using insertion and deletion, based on the Longest Common Subsequence (LCS)
int minOperations(string &s1, string &s2) {
    
    // Get the lengths of the two input strings
    int n = s1.size();
    int m = s2.size();
    
    // Variables to store current and previous diagonal values during traversal
    int current, prev;
    
    // Initialize a 1D DP array of size m+1 with all zeros
    vector<int> dp(m + 1, 0);
    
    // Loop through each character in the first string
    for(int i = 1; i <= n; i++){
        
        // Reset current and previous for each new row iteration
        current = prev = 0;
        
        // Loop through each character in the second string
        for(int j = 1; j <= m; j++){
            
            // Store the current dp[j] value as 'prev' before it gets updated
            prev = current;
            // Store the current value of dp[j] (which will be overwritten) into 'current'
            current = dp[j];
            
            // If characters match, increment the LCS length by 1
            if(s1[i - 1] == s2[j - 1])
                dp[j] = 1 + prev;
            
            // If characters don't match, take the maximum LCS by ignoring one character
            else
                dp[j] = max(dp[j], dp[j - 1]);
        }
    }
    
    // The final LCS value is stored in dp[m]
    int lcs = dp[m];
    
    // Minimum operations = deletions from s1 + insertions to s1 (or vice versa)
    return (s1.size() - lcs) + (s2.size() - lcs);
}


int main(){

    string s1 = "heap";
    string s2 = "pea";

    cout << minOperations(s1, s2);

}