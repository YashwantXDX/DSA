#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

    Refer Video :- https://www.youtube.com/watch?v=XIaqB8-wAiQ&t=2402s

    Problem States that

    Cover all the 1's present in all 8 directions to make an island.

    1 means land and 0 means water

    Simply Logic :- We will get a visited array to keep track of the 1's we have visited.

    To save the Space, We can just mark the 1 to 0 as we have to ignore the 0's and count the 1. So if we have already counted 1 and made it 0 then we dont need extra space to keep track of that.

*/

// Make Rows and Cols Direction for Navigation - Up, Down, Left, Right, Up-Left, Up-Right, Down-Left, Down-Right
int rows[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int cols[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int totalRows, totalCols;

// valid for the boundaries
bool valid(int i, int j){

    return i >= 0 && j >= 0 && i < totalRows && j < totalCols;

}

int numIslands(vector<vector<char>>& grid) {
    
    // Queue to perform BFS (Breadth-First Search) for island traversal
    queue<pair<int, int>> q;

    // Variable to count the number of islands
    int count = 0;

    // Get the total number of rows and columns in the grid
    totalRows = grid.size();
    totalCols = grid[0].size();

    // Iterate through each cell in the grid
    for(int row = 0; row < totalRows; row++) {
        for(int col = 0; col < totalCols; col++) {

            // If the cell contains '1', it is part of an island
            if(grid[row][col] == '1') {

                // Increment the island count
                count++;

                // Mark the cell as visited by changing '1' to '0'
                grid[row][col] = '0';

                // Add the current cell to the queue for BFS
                q.push(make_pair(row, col));

                // Perform BFS to traverse the entire island
                while(!q.empty()) {

                    // Get the front element from the queue
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();

                    // Traverse all 8 possible directions (up, down, left, right, diagonals)
                    for(int k = 0; k < 8; k++) {

                        // Check if the new position is valid and part of the island
                        if(valid(i + rows[k], j + cols[k]) && grid[i + rows[k]][j + cols[k]] == '1') {

                            // Add the new position to the queue
                            q.push(make_pair(i + rows[k], j + cols[k]));

                            // Mark the cell as visited
                            grid[i + rows[k]][j + cols[k]] = '0';

                        }

                    }

                }

            }

        }
    }

    // Return the total count of islands
    return count;
}


int main(){

    vector<vector<char>> mat = {
        {'0','1','1','1','0','0','0'},
        {'0','0','1','1','0','1','0'}
    };

    cout << numIslands(mat);

}