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


// This is Direct Space Optimized Approach
// Because this is similar to Longest Palindromic Subsequence

// We just have to LPS nikaalna hai and then subtract it with the size
// Thats it

// Pattern is Ditto Same as Minimum Number Of Deletion

int findMinInsertions(string &s1) { 

    int size = s1.size();
    
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
    int lps =dp[m];
    
    // Just Subtract the total size of string and lps to get the answer
    // lps contain the pallindrome
    return size - lps;
}

int main(){

    string s1 = "aba";

    cout << findMinInsertions(s1);

}