#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/knight-walk4521/1
    
    Refer Video :- https://www.youtube.com/watch?v=Dwl45Q8xQt0&t=2421s

    Just use BFS Traversal in The graph to find the path

    Time Complexity :- O(V^2)
    Space Complexity :- O(V^2)

    We can also use Dijkstra Algorithm but this is a dense graph so the
    Time Complexity will go  O(V^2 log V^2) which is very High

    So BFS is recommanded

*/

// Possible moves for a knight in chess
int rows[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int cols[8] = {1, -1, 1, -1, 2, -2, 2, -2};

// Function to check if a position (i, j) is within the chessboard boundaries
bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

// Function to find the minimum steps for a knight to reach the target position
int minSteps(vector<int> &horse, vector<int> &target, int n) {

    // If the horse is already at the target position, return 0 steps
    if (horse[0] == target[0] && horse[1] == target[1])
        return 0;

    // Convert to 0-based indexing (since input is 1-based)
    horse[0]--;
    horse[1]--;
    target[0]--;
    target[1]--;

    // Chessboard matrix to track visited positions
    vector<vector<bool>> mat(n, vector<bool>(n, 0));

    // Queue for BFS traversal (to explore all possible moves)
    queue<pair<int, int>> q;

    // Mark the horse's initial position as visited
    mat[horse[0]][horse[1]] = 1;

    // Push the starting position into the queue
    q.push({horse[0], horse[1]});

    // Step counter for tracking moves
    int step = 0;

    // BFS traversal
    while (!q.empty()) {

        // Get the number of elements in the queue (current level size)
        int size = q.size();

        // Increment step count as we move to the next level
        step++;

        while (size--) {

            // Extract the front position from the queue
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all 8 possible knight moves
            for (int k = 0; k < 8; k++) {

                // Compute new position
                int new_row = row + rows[k];
                int new_col = col + cols[k];

                // Check if the new position is the target
                if (new_row == target[0] && new_col == target[1])
                    return step;

                // Check if the new position is within bounds and not visited
                if (valid(new_row, new_col, n) && mat[new_row][new_col] == 0) {

                    // Mark the position as visited
                    mat[new_row][new_col] = 1;

                    // Add the position to the queue for further exploration
                    q.push({new_row, new_col});
                }
            }
        }
    }

    // If no path to the target is found, return -1
    return -1;
}


int main(){

    vector<int> Horse = {4,5};
    vector<int> target = {1,1};

    int n = 6;

    cout << minSteps(Horse, target, n);

}