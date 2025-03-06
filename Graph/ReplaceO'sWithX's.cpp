#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

    Refer Video :- https://www.youtube.com/watch?v=XIaqB8-wAiQ&t=4758s

    Problem States that

    We have to Convert O's into X's if all the O's or set of O's covered with the X. If any of the O or part of set of O's is in the boundaries, the set cannot be converted into X's.

    1. Check the boundaries for O's, if there is then just BFS traverse the O to get all the connections of O's
    2. Leave that set and convert the remaining O's (Covered by X) to X.

*/

// Make Rows and Cols Direction for Navigation - Up, Down, Left, Right, Up-Left, Up-Right, Down-Left, Down-Right
int rows[4]= {-1, 1, 0, 0};
int cols[4] = {0, 0, 1, -1};
int totalRows, totalCols;

// valid for the boundaries
bool valid(int i, int j){

    return i >= 0 && j >= 0 && i < totalRows && j < totalCols;

}

vector<vector<char>> fill(vector<vector<char>>& mat) {
    
    queue<pair<int, int>> q;

    // Get total number of rows and columns in the matrix
    totalRows = mat.size();
    totalCols = mat[0].size();

    // Boundary Traversal of the Matrix

    // Process the first row
    for(int i = 0; i < totalCols; i++){
        if(mat[0][i] == 'O'){
            q.push(make_pair(0, i));
            mat[0][i] = 'T'; // Mark as temporary
        }
    }

    // Process the first column
    for(int i = 1; i < totalRows; i++){
        if(mat[i][0] == 'O'){
            q.push(make_pair(i, 0));
            mat[i][0] = 'T'; // Mark as temporary
        }
    }

    // Process the last row
    for(int i = 1; i < totalCols; i++){
        if(mat[totalRows - 1][i] == 'O'){
            q.push(make_pair(totalRows - 1, i));
            mat[totalRows - 1][i] = 'T'; // Mark as temporary
        }
    }

    // Process the last column
    for(int i = 1; i < totalRows - 1; i++){
        if(mat[i][totalCols - 1] == 'O'){
            q.push(make_pair(i, totalCols - 1));
            mat[i][totalCols - 1] = 'T'; // Mark as temporary
        }
    }

    // Perform BFS to mark all connected 'O' cells
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // Check in all 4 directions
        for(int k = 0; k < 4; k++){
            if(valid(i + rows[k], j + cols[k]) && mat[i + rows[k]][j + cols[k]] == 'O'){
                q.push(make_pair(i + rows[k], j + cols[k]));
                mat[i + rows[k]][j + cols[k]] = 'T'; // Mark as temporary
            }
        }
    }

    // Convert remaining 'O' to 'X' and revert 'T' back to 'O'
    for(int i = 0; i < totalRows; i++){
        for(int j = 0; j < totalCols; j++){
            if(mat[i][j] == 'O')
                mat[i][j] = 'X';  // Flip enclosed regions
            else if(mat[i][j] == 'T')
                mat[i][j] = 'O';  // Restore boundary-connected regions
        }
    }

    return mat;
}


int main(){

    vector<vector<char>> mat = {
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

    vector<vector<char>> ans = fill(mat);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}