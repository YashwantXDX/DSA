#include<bits/stdc++.h>
using namespace std;

/*

    Note :- IMPORTANT QUESTION
    
    Problem Link :- https://www.geeksforgeeks.org/problems/number-of-unique-paths5339/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/

// Function to count the number of unique paths from top-left to bottom-right in a grid
int NumberOfPath(int a, int b)
{
    // Create a 2D DP table with dimensions a x b, initialized with 1s
    // Each cell initially represents one path (base case for last row/column)
    vector<vector<int>> dp(a, vector<int> (b, 1));
    
    // Start filling the DP table from second last row and column towards top-left
    for(int i = a - 2; i >= 0; i--)            // Iterate rows from bottom to top
        for(int j = b - 2; j >= 0; j--)        // Iterate columns from right to left
            // The number of paths to reach bottom-right from cell (i, j) is the
            // sum of paths from the cell below and the cell to the right
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    
    // Return the number of paths from the starting cell (0, 0)
    return dp[0][0];
}

// Space Optimized version
// Function to count the number of unique paths from top-left to bottom-right in a grid
int NumberOfPath(int a, int b)
{
    // Create a 1D DP array of size 'b' initialized with 1s
    // Each element represents the number of paths from the bottom row
    vector<int> dp(b, 1);
    
    // Iterate from the second last row up to the first row
    for(int i = a - 2; i >= 0; i--)
        // For each row, iterate from the second last column to the first
        for(int j = b - 2; j >= 0; j--)
            // Update dp[j] by adding the number of paths from the cell to the right
            // dp[j] (down cell) + dp[j + 1] (right cell)
            dp[j] += dp[j + 1];
    
    // dp[0] now holds the number of unique paths from the top-left corner (0, 0)
    return dp[0];
}


int main(){

    int a = 3, b = 4;

    cout << NumberOfPath(a, b);

}