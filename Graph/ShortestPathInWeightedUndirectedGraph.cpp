#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

    Refer Video :- https://www.youtube.com/watch?v=6-O4MehzsaA

    Problem Logic :-

    The given problem is about finding the shortest path from node 1 to node n in a weighted undirected graph using Dijkstra’s Algorithm.

        The graph is represented using an adjacency list.
        The algorithm uses a priority queue (min-heap) to always expand the minimum distance node first.
        It maintains a distance array to keep track of the shortest known distances from node 1 to all other nodes.
        A parent array is used to reconstruct the shortest path from node 1 to node n.
        If there is no path to node n, return {-1}.
        Otherwise, construct the shortest path and return it along with the total distance.


    Algorithm Steps:-

    Step 1: Construct the Graph
        i. Create an adjacency list to store the nodes and edge weights.
        ii. Since the graph is undirected, store both directions of each edge.

    Step 2: Initialize Dijkstra's Algorithm
        i. Create a distance array (dist) and initialize all values to INT_MAX, except dist[1] = 0 (starting node).
        ii. Create a visited array to mark processed nodes.
        iii. Create a parent array initialized with -1 to reconstruct the shortest path.
        iv. Use a min-heap (priority queue) to always process the node with the smallest distance first.

    Step 3: Process Nodes in the Priority Queue
        i. While the priority queue is not empty:
            a. Extract the node with the smallest distance.
            b. If the node is already visited, continue.
            c. Mark the node as visited.
            d. Iterate through all its neighbors and update their distances if a shorter path is found.
            e. Store the parent node for path reconstruction.
            
    Step 4: Construct the Shortest Path
        i. If parent[n] == -1, return {-1} (no path exists).
        ii. Otherwise, trace backward from node n to node 1 using the parent array and store the path.
        iii. Append the total distance from 1 to n at the end of the path.
        iv. Reverse the path to get the correct order (1 → n).
        v. Return the shortest path with distance.

*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

    // adjecency List bnao
    // 1 based index
    // Adjacency list representation of the graph
    vector<pair<int, int>> adj[n + 1]; // Each node has a list of {neighbor, weight} pairs

    // Read edges and construct the adjacency list
    for(int i = 0; i < m; i++) {
        int edge1 = edges[i][0]; // First node of the edge
        int edge2 = edges[i][1]; // Second node of the edge
        int weight = edges[i][2]; // Weight of the edge

        // Since the graph is undirected, add both directions
        adj[edge1].push_back({edge2, weight});
        adj[edge2].push_back({edge1, weight});
    }

    // Dijkstra's Algorithm to find the shortest path
    vector<int> dist(n + 1, INT_MAX); // Distance array, initialized to infinity
    vector<bool> visited(n + 1, 0); // Visited array to track processed nodes
    vector<int> parent(n + 1, -1); // Parent array to store the shortest path tree

    // Min-heap (priority queue) to process nodes with the smallest distance first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    // Push the source node (node 1) with a distance of 0
    p.push({0, 1});
    dist[1] = 0;

    while(!p.empty()) {
        int node = p.top().second; // Get the node with the smallest distance
        p.pop();

        // If the node is already visited, skip processing
        if(visited[node]) continue;

        visited[node] = 1; // Mark the node as visited

        // Traverse all neighbors of the current node
        for(int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i].first; // Neighboring node
            int weight = adj[node][i].second; // Weight of the edge

            // Relaxation step: if a shorter path is found, update distance
            if(!visited[neighbour] && dist[neighbour] > dist[node] + weight) {
                dist[neighbour] = dist[node] + weight; // Update distance
                p.push({dist[neighbour], neighbour}); // Push updated distance into heap

                // Update the parent to reconstruct the shortest path later
                parent[neighbour] = node;
            }
        }
    }

    // If there is no path to node n, return {-1}
    if(parent[n] == -1) return {-1};

    // Retrieve the shortest path from node 1 to node n
    vector<int> path;
    int destination = n;

    while(destination != -1) {
        path.push_back(destination); // Add the current node to the path
        destination = parent[destination]; // Move to the parent node
    }

    // Append the shortest distance from node 1 to node n
    path.push_back(dist[n]);

    // Reverse the path to get it in correct order (1 -> n)
    reverse(path.begin(), path.end());

    return path;

}


int main(){
    vector<vector<int>> edges  = {
        {1,2,2},
        {2,5,5},
        {2,3,4},
        {1,4,1},
        {4,3,3},
        {3,5,1},
    };
    
    int n = 5, m = 6;

    vector<int> ans = shortestPath(n, m, edges);

    for(int i : ans)
        cout << i << " ";
}