#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

    Refer Video :- https://www.youtube.com/watch?v=1YoCOUBw1zU

    Problem Algorithm :- 

    Steps:

    Step 1: Create an Adjacency List  
    1. Initialize an adjacency list `adj`, where each node stores a list of its neighboring nodes along with the corresponding edge weight.  
    2. Loop through the `edges` list and populate the adjacency list.  

    Step 2: Perform Topological Sorting Using DFS  
    3. Create a `visited` list to track visited nodes.  
    4. Create an empty stack `s` to store nodes in topological order.  
    5. Define a recursive function `DFS(node)` that:  
    - Marks `node` as visited.  
    - Recursively visits all unvisited neighbors.  
    - Pushes the `node` onto the stack after visiting all its neighbors.  
    6. Start DFS from node `0` to compute topological order.  

    Step 3: Find Shortest Path Using Topological Order  
    7. Initialize a `dist` array with `INT_MAX` (∞) for all nodes, except the source (`dist[0] = 0`).  
    8. Process nodes in topological order (by popping from `stack`):  
    - For each neighbor, update its shortest distance using the formula:  
        
        dist[neighbour] = min( dist[neighbour] , weight + dist[node] ) 

    Step 4: Convert Unreachable Nodes to -1  
    9. Replace all `INT_MAX` values in `dist` with `-1` to indicate unreachable nodes.  

    Step 5: Return the Shortest Distance Array  
    10. Return the final `dist` array.

*/

// Depth-First Search (DFS) function to perform Topological Sorting
void DFS(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &s) {

    // Mark the current node as visited
    visited[node] = true;

    // Traverse all adjacent nodes
    for (int i = 0; i < adj[node].size(); i++) {
        // If the neighbor is not visited, perform DFS on it
        if (!visited[adj[node][i].first])
            DFS(adj[node][i].first, adj, visited, s);
    }

    // Push the node onto the stack after visiting all its neighbors
    s.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    
    // Step 1: Create an adjacency list to store directed edges with weights
    vector<pair<int, int>> adj[V];

    for (int i = 0; i < E; i++) {
        int edge = edges[i][0];   // Source node
        int vertex = edges[i][1]; // Destination node
        int weight = edges[i][2]; // Weight of the edge

        // Store the directed edge in the adjacency list
        adj[edge].push_back({vertex, weight});
    }

    // Step 2: Perform Topological Sorting using DFS
    stack<int> s;               // Stack to store topologically sorted nodes
    vector<bool> visited(V, false);  // Track visited nodes

    // Perform DFS from the source node (0) to get topological order
    DFS(0, adj, visited, s);

    // Step 3: Initialize distance array
    vector<int> dist(V, INT_MAX); // Set all distances to infinity initially
    dist[0] = 0;                  // Distance to the source node is 0

    // Step 4: Process nodes in topological order
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        // Update distances for all adjacent nodes
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i].first;  // Adjacent node
            int weight = adj[node][i].second;    // Edge weight

            // Relax the edge if a shorter path is found
            if (dist[node] != INT_MAX) {
                dist[neighbour] = min(dist[neighbour], weight + dist[node]);
            }
        }
    }

    // Step 5: Convert unreachable nodes (INT_MAX) to -1
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    
    return dist; // Return the shortest distance array
}

int main(){

    vector<vector<int>> edges = {
        {0,1,2},
        {0,4,1},
        {4,5,4},
        {4,2,2},
        {1,2,3},
        {2,3,6},
        {5,3,1}
    };

    int v = 6, e = 7;

    vector<int> ans = shortestPath(v, e, edges);

    for(int i : ans)
        cout << i << " ";

}