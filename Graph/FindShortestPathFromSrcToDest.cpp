#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM

    Refer Video :- https://www.youtube.com/watch?v=1pL11W_0H2g&t=2261s

*/

vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int dest) {
    
    // Adjacency list to represent the graph (using 0-based indexing)
    vector<int> adj[N];

    // Convert input edges from 1-based to 0-based indexing and construct the adjacency list
    for (int i = 0; i < M; i++) {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    // Convert source and destination to 0-based indexing
    src--; 
    dest--;

    // Parent array to track the path (stores the previous node in the shortest path)
    vector<int> parent(N, -1);

    // Visited array to track whether a node has been processed
    vector<bool> visited(N, false);
    
    // Queue for BFS traversal
    queue<int> q;
    
    // Start BFS from the source node
    q.push(src);
    visited[src] = true;
    
    // Perform BFS to find the shortest path
    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        // Traverse all adjacent nodes of the current node
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            // If already visited, skip it
            if (visited[neighbor])
                continue;

            // Mark as visited and push into the queue
            visited[neighbor] = true;
            q.push(neighbor);

            // Store the parent node to reconstruct the path later
            parent[neighbor] = node;
        }
    }

    // Vector to store the shortest path
    vector<int> path;

    // Reconstruct the path from destination to source using the parent array
    while (dest != -1) {
        path.push_back(dest + 1); // Convert back to 1-based indexing
        dest = parent[dest];
    }

    // Reverse the path to get the correct order from source to destination
    reverse(path.begin(), path.end());

    return path;
}


int main(){

    vector<pair<int, int>> edge = {
        {1, 3}, {3, 1}, {1, 2}, {2, 1}, {1, 4}, {4, 1},
        {4, 6}, {6, 4}, {6, 7}, {7, 6}, {7, 8}, {8, 7},
        {3, 8}, {8, 3}, {2, 5}, {5, 2}, {5, 8}, {8, 5}
    };

    int src = 1;
    int dest = 8;

    vector<int> ans = shortestPath(edge, 8, edge.size(), src, dest);

    for(int i : ans)
        cout << i << " ";

}