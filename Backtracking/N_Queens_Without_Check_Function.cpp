#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/n-queens/

    Refer Video :- https://www.youtube.com/watch?v=EYM_lIVYJak

    Problem Logic :- 

    The N-Queens problem is a classic backtracking problem where we need to place N queens on an N × N chessboard such that no two queens can attack each other.

    A queen in chess moves:

        Horizontally (left/right)
        Vertically (up/down)
        Diagonally (both left and right)

    This means that when placing a queen on the board, we need to ensure:

        No other queen is in the same column.
        No other queen is in the same diagonal (left or right).
    
    Steps to Solve:

    Start placing queens row by row.

    For each row, try placing a queen in each column.

    Before placing a queen, check:
        If the column is not occupied.
        If the left diagonal is clear.
        If the right diagonal is clear.

    If the position is valid, place the queen and move to the next row.
    
    If we reach the last row, we found a valid arrangement. Save the board.

    Use backtracking to remove the last placed queen and try the next possibility.

*/

void find(int row, int &n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDig, vector<bool> &RightDig){

    // Agar hum end of the board poch gye mtlb hume answer mil gya hai
    // Usko answer me push kro and return maar do
    if(row == n){
        ans.push_back(Board);
        return;
    }

    // Ek ek kar ke valid position me queens daalo
    for(int i = 0; i < n; i++){

        // Get the left and right diagonal number
        int leftDig = n - 1 + i - row;
        int rightDig = row + i;

        // Agar current position in column agar false hai
        // orr Diagonals me bhi koi queen present nhi hai
        // mtlb hum uss position me queen rkh skte hai
        if(column[i] == false && LeftDig[leftDig] == false && RightDig[rightDig] == false){

            // Current position of column ko true mark kro
            column[i] = true;

            // mark the Left Diagonal as queen present and for right diagonal too
            LeftDig[leftDig] = true;
            RightDig[rightDig] = true;

            // Board pe queen rkh do
            Board[row][i] = 'Q';

            // Ab position ke niche wale row me queen rkhne ki position dhundo
            find(row + 1, n, ans, Board, column, LeftDig, RightDig);

            // ------ BackTracking Part ----

            // Current position of column ko false kr do as we are removing the queen
            column[i] = false;

            // Mark the Left and Right Diagonals as empty as there is no queen
            LeftDig[leftDig] = false;
            RightDig[rightDig] = false;

            // Board me se queen hta ke empty position kar do
            Board[row][i] = '.';

        }
            
    }

}

vector<vector<string>> solveNQueens(int n) {
    
    // . means Empty space
    // Q means Queen


    // Answer vector
    vector<vector<string>> ans;

    // To know instantly weather a queen can be placed in that column
    vector<bool> column(n, false);

    // Chess Board 2D
    vector<string> Board(n);

    // vector for left and right diagonal with size 2 * n - 1
    vector<bool> LeftDig(2 * n - 1, false), RightDig(2 * n - 1, false);

    // Create an empty board
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            Board[i].push_back('.');
    
    // Check from the starting of the board
    find(0, n, ans, Board, column, LeftDig, RightDig);

    return ans;
            
}

int main(){

    int n = 4;

    vector<vector<string>> ans = solveNQueens(n);

    for (const auto &board : ans) { 
        for (const auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

}