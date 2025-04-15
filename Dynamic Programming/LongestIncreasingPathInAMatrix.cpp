#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1

    In This Problem Both DP and DFS is Used.

    DP to store the values and DFS for finding the longest path
       
*/

// Directions: Down, Up, Right, Left
int rows[4] = {1, -1, 0, 0};
int cols[4] = {0, 0, 1, -1};

// Function to check if a cell (i, j) is within the matrix boundaries
bool check(int i, int j, int n, int m) {
    return i > -1 && i < n && j > -1 && j < m;
}

// DFS function to compute the longest increasing path starting from cell (i, j)
void DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &path, int n, int m) {
    
    // Mark current cell's path length as 1 (at least itself)
    path[i][j] = 1;

    // Explore all 4 directions from the current cell
    for(int k = 0; k < 4; k++) {

        int row = i + rows[k]; // New row index
        int col = j + cols[k]; // New column index

        // Check if the new cell is within bounds and its value is greater (increasing path)
        if(check(row, col, n, m) && matrix[i][j] < matrix[row][col]) {

            // If the next cell hasn't been visited yet, call DFS on it
            if(path[row][col] == 0) {
                DFS(row, col, matrix, path, n, m);
            }

            // Update the path length of current cell using the max of its current value and 1 + neighbor's path
            path[i][j] = max(path[i][j], 1 + path[row][col]);
        }
    }
}

// Main function to find the longest increasing path in the matrix
int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

    // 2D array to store the length of longest path starting from each cell
    vector<vector<int>> path(n, vector<int>(m, 0));

    int total = 0; // To keep track of the overall longest increasing path

    // Go through every cell in the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            // If this cell hasn't been visited yet, start DFS from here
            if(path[i][j] == 0) {
                DFS(i, j, matrix, path, n, m); // Fill the path matrix from (i, j)
                total = max(total, path[i][j]); // Update the global maximum
            }
        }
    }

    // Return the length of the longest increasing path found
    return total;
}

int main(){

    int n = 3;
    int m = 3;

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << longestIncreasingPath(matrix, n, m);

}