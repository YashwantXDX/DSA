#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

    Refer Video :- https://www.youtube.com/watch?v=1pL11W_0H2g

*/

// BFS
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
    // Distance array initialized with -1 (indicating unvisited nodes)
    vector<int> dist(adj.size(), -1);
    
    // Visited array to track which nodes have been processed
    vector<bool> visited(adj.size(), 0);
    
    // Queue for BFS traversal
    queue<int> q;
    
    // Start BFS from the source node
    q.push(src);
    visited[src] = 1;  // Mark source as visited
    dist[src] = 0;      // Distance to itself is 0
    
    // BFS traversal
    while (!q.empty()) {
        
        int node = q.front(); 
        q.pop();
        
        // Traverse all adjacent nodes of the current node
        for (int i = 0; i < adj[node].size(); i++) {
            
            int neighbor = adj[node][i]; // Get the adjacent node
            
            // If the node is already visited, skip it
            if (visited[neighbor])
                continue;
            
            // Mark the node as visited
            visited[neighbor] = 1;
            
            // Push it into the queue for further processing
            q.push(neighbor);
            
            // Update the shortest distance from the source
            dist[neighbor] = dist[node] + 1;
        }
    }
    
    // Return the distance array containing shortest distances from source
    return dist;
}

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    
}

int main(){

    vector<vector<int>> mat = {
        {1,3},
        {0,2},
        {1,6},
        {0,4},
        {3,5},
        {4,6},
        {2,5,7,8},
        {6,8},
        {7,6}
    };

    int src = 0;

    vector<int> ans = shortestPath(mat, src);

    for(int i : ans)
        cout << i << " ";

}