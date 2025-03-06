#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/covid-spread--141631/1

    Refer Video :- https://www.youtube.com/watch?v=XIaqB8-wAiQ

    Problem States that

    0 - Empty Room
    1 - Uninfected Person
    2 - Infected Person

*/

// For Navigation - Up, Down, Left, Right
int rows[4] = {-1, 1, 0, 0};
int cols[4] = {0, 0, 1, -1};
int totalRows, totalCols;

// Check for validation like not to go beyond the boundary
bool valid(int i, int j){
    
    return i >= 0 && j >= 0 && i < totalRows && j < totalCols;
    
}

int helpaterp(vector<vector<int>> hospital)
{
    // Initialize the global variable with the rows and cols in the hospital matrix
    totalRows = hospital.size();
    totalCols = hospital[0].size();
    
    // Make a queue to get all the infected patients
    queue<pair<int, int>> q;

    // Initialize the time by 0
    int time = 0;
    
    // Get the Infected persons room by row and col and push them in queue
    for(int i = 0; i < totalRows; i++)
        for(int j = 0; j < totalCols; j++)
            if(hospital[i][j] == 2)
                q.push(make_pair(i, j));
    
    // Till Queue goes empty
    while(!q.empty()){
        
        // Increase the time
        time++;

        // Get the current size of the queue, this is to get all the infected person can infect the uninfected person in a single time
        int size = q.size();
        
        while(size--){
            
            // fetch the front of the queue, row and col
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // To Traverse all the direction, BFS Traversal
            for(int k = 0; k < 4; k++){
                
                // If the current row and col are valid and also they contain uninfected person in their path
                if(
                    valid(i + rows[k], j + cols[k]) 
                    && hospital[i + rows[k]][j +cols[k]] == 1){
                        
                        // Infect them and push them into the queue
                        q.push(make_pair(i + rows[k], j + cols[k]));
                        hospital[i + rows[k]][j +cols[k]] = 2;
                        
                    }
                
            }
            
        }
        
    }
    
    // Special Condition where all the rooms are empty
    bool gotZeros = 1;
    
    // Check if there is any remaining uninfected person, if there is then return -1 as not all the persons can be infected
    // Special Condition :- Also check if there are all the 0 present in the matrix
    for(int i = 0; i < totalRows; i++){
        for(int j = 0; j < totalCols; j++){
            if(hospital[i][j] == 1)
                return -1;
            if(hospital[i][j] != 0)
                gotZeros = 0;
        }
    }
    
    // If there is all 0 in the matrix then simply return 0
    if(gotZeros) return 0;
    
    // Return time - 1, as we took an infected one to infect the person but no person was available but we counted the time
    return time - 1;
}

int main(){

    vector<vector<int>> mat = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    cout << helpaterp(mat);

}