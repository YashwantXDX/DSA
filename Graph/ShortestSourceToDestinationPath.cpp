#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

    Refer Video :- https://www.youtube.com/watch?v=Dwl45Q8xQt0

*/

// Directions for moving in 4 possible ways (up, down, left, right)
int rows[4] = {1, -1, 0, 0};
int cols[4] = {0, 0, 1, -1};

// Function to check if a given cell (i, j) is within the grid boundaries
bool valid(int i, int j, int N, int M) {
    return i >= 0 && j >= 0 && i < N && j < M;
}

/*

    Solution 1 with Extra Space - Visited Array

*/

// Function to find the shortest path from (0,0) to (X,Y) in a grid
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    
    // If the destination is the starting point, return 0
    if (X == 0 && Y == 0)
        return 0;

    // If the starting position is blocked, return -1
    if (A[0][0] == 0)
        return -1;
    
    // Queue to perform BFS (stores step count and the current cell)
    queue<pair<int, pair<int, int>>> q;
    
    // 2D array to keep track of visited cells
    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    
    // Start BFS from (0,0) with 0 steps
    q.push({0, {0, 0}});
    visited[0][0] = 1;
    
    // BFS traversal
    while (!q.empty()) {
        
        // Get the front element from the queue
        int step = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        
        q.pop(); // Remove the front element
        
        // Explore all four possible directions
        for (int k = 0; k < 4; k++) {
            
            int new_row = row + rows[k];
            int new_col = col + cols[k];
            
            // Check if the new position is valid, not visited, and has a valid path (1)
            if (
                valid(new_row, new_col, N, M) &&
                !visited[new_row][new_col] &&
                A[new_row][new_col] == 1
            ) {
                
                // If we reached the destination, return the step count
                if (new_row == X && new_col == Y)
                    return step + 1;
                
                // Mark the new position as visited
                visited[new_row][new_col] = 1;
                
                // Push the new position into the queue with incremented step count
                q.push({step + 1, {new_row, new_col}});
            }
        }
    }
    
    // If no path is found, return -1
    return -1;
}

/*

    Solution 2 without extra Space and step  - Visited array and step pair

*/

// Function to find the shortest path from (0,0) to (X,Y) in a grid
int shortestDistance2(int N, int M, vector<vector<int>> A, int X, int Y) {
    
    // If the destination is the starting point, return 0
    if (X == 0 && Y == 0)
        return 0;

    // If the starting position is blocked, return -1
    if (A[0][0] == 0)
        return -1;
    
    // Queue to perform BFS (stores step count and the current cell)
    queue<pair<int, int>> q;
    
    // Start BFS from (0,0) with 0 steps
    q.push({0, 0});

    // Mark the position with 0 as we dont want to visit that again
    A[0][0] = 0;
    
    // Just keep track of the count
    int count = 0;

    // BFS traversal
    while (!q.empty()) {

        // Increase the count of the current Level
        count++;

        // Get the current level queue size
        int size = q.size();

        // Jab tk current level chl rha hai tb tk chlo
        while(size--){
        
            // Get the front element from the queue
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop(); // Remove the front element
            
            // Explore all four possible directions
            for (int k = 0; k < 4; k++) {
                
                int new_row = row + rows[k];
                int new_col = col + cols[k];
                
                // Check if the new position is valid, not visited, and has a valid path (1)
                if (
                    valid(new_row, new_col, N, M) &&
                    A[new_row][new_col] == 1
                ) {
                    
                    // If we reached the destination, return the step count
                    if (new_row == X && new_col == Y)
                        return count;
                    
                    // Mark the new position as 0 as we dont want to visited that
                    A[new_row][new_col] = 0;

                    // Push the new position into the queue with incremented step count
                    q.push({new_row, new_col});
                }
            }
        }
    }

    // If no path is found, return -1
    return -1;
}

int main(){

    vector<vector<int>> mat = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,1,1},
    };

    int X = 2, Y = 3;

    cout << shortestDistance2(3, 4, mat, X, Y);

}