#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Refer Video :- https://www.youtube.com/watch?v=sPlN86EpjJA

    Problem Logic :- 

    1. Function `detectCycle(node, adj, path, visited)`:  

    - Mark the `node` as visited.  
    - Mark `node` as part of the current path (to track cycles).  
    - Check all connected nodes:  
        - If a connected node is already in the path, a cycle exists → return `true`.  
        - If a connected node is visited but not in the path, ignore it.  
        - If a connected node is unvisited, recursively check for cycles in it.  
    - After checking, remove `node` from the path and return `false` (no cycle found).  

    2. Function `isCyclic(adj)`:
    
    - Create `visited` and `path` lists, marking all nodes as unvisited.  
    - Check each node:  
        - If it is unvisited, call `detectCycle` to check for cycles.  
        - If `detectCycle` returns `true`, a cycle is found → return `true`.  
    - If all nodes are checked and no cycle is found, return `false`.

*/

bool detectCycle(int node, vector<vector<int>> &adj, vector<bool> &path, vector<bool> &visited){
    
    // Mark the current node as visited and path as true
    visited[node] = true;
    path[node] = true;

    // Check for the node's connection
    for(int i = 0; i < adj[node].size(); i++){
        
        // If the node's path is already visited, that means there is a cycle
        if(path[adj[node][i]] == true)
            return true;
        
        else{
            
            // If there is no cycle but the node is visited by another path, we have to continue to save the Time.
            if(visited[adj[node][i]] == true)
                continue;
            
            // If we found that the current node has a cycle present, then return true
            if(detectCycle(adj[node][i], adj, path, visited) == true)
                return true;
            
        }
        
    }
    
    // before going out of the function, mark the path as false
    path[node] = false;
    
    // If no cycle detected in the current node, then return false
    return false;
    
}

bool isCyclic(vector<vector<int>> &adj) {
    
    // Initialize the visited and path as false with the size of adj
    vector<bool> visited(adj.size(), 0), path(adj.size(), 0);
    
    // Check for each node (by Default node starts from 0)
    for(int i = 0; i < adj.size(); i++){
        
        // Check if the node is unvisited and there is a cycle present in that node, if yes, then return true
        if(!visited[i] && detectCycle(i, adj, path, visited) == true)
            return true;
        
    }
    
    // Every thing is fine
    return false;
    
}

int main(){

    vector<vector<int>> matrix = {
        {1},
        {2},
        {3},
        {3}   
    };
    
    cout << isCyclic(matrix);

    
}