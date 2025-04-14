#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://leetcode.com/problems/minimum-path-sum/

    We can just Do it in Space Complexity of O(1).
    Instead of creating extra space, we can update in the grid only.

    MUST DRY RUN

*/

// TC - O(n * m)
//SC - O(1)

int minPathSum(vector<vector<int>>& grid) {
    
    // Get the number of rows in the grid
    int n = grid.size();

    // Get the number of columns in the grid
    int m = grid[0].size();

    // Fill the last row from right to left, summing up values to find the minimum path
    for(int i = m - 1; i >= 1; i--)
        grid[n - 1][i - 1] = grid[n - 1][i] + grid[n - 1][i - 1];
        // Each cell gets updated with the value to its right (since we can only move right or down)

    // Fill the last column from bottom to top
    for(int i = n - 1; i >= 1; i--)
        grid[i - 1][m - 1] = grid[i][m - 1] + grid[i - 1][m - 1];
        // Each cell gets updated with the value below it (because we can only move down or right)

    // Fill the rest of the grid starting from bottom-right moving towards top-left
    for(int i = n - 2; i >= 0; i--){ // Loop through rows from second last to first
        for(int j = m - 2; j >= 0; j--){ // Loop through columns from second last to first

            // For each cell, take the minimum of the path going right or down, and add current cell value
            grid[i][j] = min((grid[i][j + 1] + grid[i][j]), (grid[i + 1][j] + grid[i][j]));
        }
    }

    // The top-left cell now contains the minimum path sum from top-left to bottom-right
    return grid[0][0];
}


int main(){

    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6}
    };

}