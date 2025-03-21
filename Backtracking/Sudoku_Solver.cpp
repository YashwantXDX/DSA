#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/sudoku-solver/

    Refer Video :- https://www.youtube.com/watch?v=EYM_lIVYJak&t=6953s

*/

bool check(int num, vector<vector<char>> &board, int &row, int &col){

    char c = '0' + num;

    // check row
    // If the char is present then return false
    for(int i = 0; i < 9; i++)
        if(board[i][col] == c)
            return false;

    // check col
    // If the char is present then return false
    for(int i = 0; i < 9; i++)
        if(board[row][i] == c)
            return false;
    
    // Check the box
    
    // Extract the current box by row and col
    // If the char is present then return false
    int rowBox = (row / 3) * 3;
    int colBox = (col / 3) * 3;

    for(int i = rowBox; i < rowBox + 3; i++)
        for(int j = colBox; j < colBox + 3; j++)
            if(board[i][j] == c)
                return false;
    
    return true;

}

bool solve(int row, int col, vector<vector<char>> &board){

    // Agar row equal ho jaya hai 9 ke, mtlb sudoku solve hogya hai
    if(row == 9)
        return true;
    
    // Agar col equal ho jata hai 9 ke mtlb hume ab row change krna hai
    if(col == 9)
        return solve(row + 1, 0, board);

    // Agar Empty space nhi hai to skip kro uss place ko
    if(board[row][col] != '.')
        return solve(row, col + 1, board);

    // Agar empty space mil gyi hai to value put kro 1 - 9 me se
    for(int i = 1; i < 10; i++){

        // Check if it is valid number to be placed in that position
        // Agar valid hai to put kro
        if(check(i, board, row, col)){

            // i ki value ko char me badlo orr board me daal do
            board[row][col] = '0' + i;
        
            // Agar aage values bhar skte hai to true return karo
            if(solve(row, col + 1, board))
                return true;
            
            // Agar value nhi bhar skte to backtrack kro
            // orr jo value abhi bhra hai use empty kar do
            board[row][col] = '.';
        }

    }

    // bta do upar ki nhi bhr skte value ko
    return false;

}

void solveSudoku(vector<vector<char>>& board) {
    
    // Row, Col, Board bhej do
    solve(0, 0, board);

}

int main(){

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

}