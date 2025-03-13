#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/find-whether-path-exist5238/1

    Refer Video :- https://www.youtube.com/watch?v=Dwl45Q8xQt0&t=3913s

*/

// Possible moves for 4-directional traversal (Up, Down, Left, Right)
int rows[4] = {1, -1, 0, 0};
int cols[4] = {0, 0, 1, -1};

// Function to check if a position (i, j) is within grid boundaries
bool valid(int i, int j, int N) {
    return i >= 0 && j >= 0 && i < N && j < N;
}

// Function to check if a path exists from source (1) to destination (2)
bool is_Possible(vector<vector<int>>& grid) 
{
    // If the grid has only one cell, it's impossible to have a path
    if (grid.size() == 1) return false;
    
    // Variables to store source and destination positions
    int src[2], dest[2];

    // Find the positions of source (1) and destination (2) in the grid
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {  // Source found
                src[0] = i;
                src[1] = j;
            }
            else if (grid[i][j] == 2) {  // Destination found
                dest[0] = i;
                dest[1] = j;
            }
        }
    }

    // BFS traversal from the source to the destination

    // Queue to store grid positions for BFS traversal
    queue<pair<int, int>> q;

    // Add source position to the queue
    q.push({src[0], src[1]});

    // Mark the source as visited (block the path)
    grid[src[0]][src[1]] = 0;

    while (!q.empty()) {
        // Extract the front position from the queue
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Check all four possible directions (Up, Down, Left, Right)
        for (int k = 0; k < 4; k++) {
            // Compute new position based on direction
            int new_row = row + rows[k];
            int new_col = col + cols[k];
            
            cout << new_row << " " << new_col << endl;  // Debug output
            
            // Check if we reached the destination
            if (new_row == dest[0] && new_col == dest[1])
                return true;
            
            // Check if the new position is within bounds and has a valid path (3)
            if (valid(new_row, new_col, grid.size()) && grid[new_row][new_col] == 3) {
                // Mark the position as visited (block the path)
                grid[new_row][new_col] = 0;

                // Add the new position to the queue for further exploration
                q.push({new_row, new_col});
            }
        }
    }

    // If no path to the destination is found, return false
    return false;
}


int main(){

    vector<vector<int>> grid = {
        {3,0,3,0,0},
        {3,0,0,0,3},
        {3,3,3,3,3},
        {0,2,3,0,0},
        {3,0,0,1,3}
    };

    cout << "Path Hai ? " << (is_Possible(grid) ? "\nHa Path Hai" : "\nChutiya Bnaya Tumko");

}