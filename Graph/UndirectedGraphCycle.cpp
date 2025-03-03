#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    Refer Video :- https://www.youtube.com/watch?v=oz1EaP_Bw4s

*/

bool detect(int node, int parent, vector<vector<int>> &mat, vector<bool> &visited){

    // Mark the node as visited
    visited[node] = 1;

    // Check for the connections of the node
    for(int i = 0; i < mat[node].size(); i++){

        // If the current node is parent then skip
        if(parent == mat[node][i]) continue;

        // If the node is already visited that means cycle is there
        if(visited[mat[node][i]]) return true;
        
        // Check if the recursive call gave the true value as return
        if(detect(mat[node][i], node, mat, visited)) return true;

    }

    // Every Thing is Fine, No Cycle
    return false;

}

bool isCycle(vector<vector<int>> &adj){

    // Visited Array
    vector<bool> visited(adj.size(), 0);

    // Check All the elements visited
    for(int i = 0; i < adj.size(); i++){

        // If any node is found unvisited and that node has cycle in it
        if(!visited[i] && detect(i, -1, adj, visited))
            return 1;

    }

    return 0;

}

int main(){

    vector<vector<int>> matrix = {
        {1, 2},
        {0, 7, 5},
        {0, 3, 4},
        {2},
        {2},
        {1, 6},
        {5, 8},
        {1, 8},
        {6, 7}};
    
    cout << "Cycle ? :- " << isCycle(matrix);


}