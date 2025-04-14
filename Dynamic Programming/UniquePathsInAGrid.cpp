#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

    We can just Do it in Space Complexity of O(1).
    Instead of creating extra space, we can update in the grid only.

*/

// TC - O(n * m)
//SC - O(1)

// Function to count unique paths from top-left to bottom-right avoiding obstacles (0s)
int uniquePaths(int n, int m, vector<vector<int>> &grid) {
    
    // If starting or ending cell is blocked, no path exists
    if(grid[0][0] == 0 || grid[n - 1][m - 1] == 0) return 0;
    
    // Flag to track if a 0 (obstacle) has been encountered in the last row
    bool zeroCountered = false;
    
    // Process the last row from right to left
    for(int i = m - 1; i >= 0; i--) {
        
        // If a 0 is encountered, mark the flag
        if(grid[n - 1][i] == 0)
            zeroCountered = true;
        
        // If any cell to the right is 0 (or current one), this cell also can't be part of a path
        if(zeroCountered)
            grid[n - 1][i] = 0;
    }
    
    // Reset the flag for last column processing
    zeroCountered = false;
    
    // Process the last column from bottom to top
    for(int i = n - 1; i >= 0; i--) {
        
        // If a 0 is encountered, mark the flag
        if(grid[i][m - 1] == 0)
            zeroCountered = true;
        
        // If any cell below is 0 (or current one), this cell also can't be part of a path
        if(zeroCountered)
            grid[i][m - 1] = 0;
    }
    
    // Fill the rest of the grid from bottom-right to top-left
    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 2; j >= 0; j--) {
            
            // If the current cell is not an obstacle
            if(grid[i][j] != 0)
                // Sum of paths from the cell below and the cell to the right (modulo to prevent overflow)
                grid[i][j] = (grid[i + 1][j] + grid[i][j + 1]) % 1000000007;
        }
    }
    
    // Return the total number of unique paths from the top-left cell
    return grid[0][0];
}


int main(){

    int n = 5, m = 5;
    vector<vector<int>> grid = {
        {1,1,1,1,1},
        {1,0,1,1,1},
        {1,1,1,1,0},
        {1,1,1,1,1},
        {1,0,1,1,1}
    };

}