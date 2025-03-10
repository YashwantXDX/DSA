#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

    Refer Video :- https://www.youtube.com/watch?v=lUXl7GnH9xk&t=1423s

    Time Complexity :- O(V^2)
    Space Complexity :- O(V)

    Problem Logic :-

    1. Select the vertex which is not explored yet and its distance is minimum among all the unexplored vertexes.

    2. Relax The Edges : 
        i. Look at your all the unexplored neighbour
        
        ii. if(dist[node] + weight < dist[neighbour]){

                dist[neighbour] = dist[node] + weight;

        }


    Algorithm Steps:-

    1. Initialize Distance Array:

        i. Create an array dist[] and set all values to ∞ (INT_MAX), except for dist[src] = 0.
        ii. Create a boolean array visited[] and set all values to false.
    
    2. Repeat for all nodes in the graph:

        i. Find the unvisited node with the smallest distance from dist[].
        ii. Mark this node as visited.
    
    3. Relaxation Step:

        i. For each neighbor of the current node:
            a. If it is not visited and the new path distance (current_distance + edge_weight) is smaller than dist[neighbor], then update dist[neighbor].
    
    4. Repeat until all nodes are processed.

    5. Return the dist[] array containing the shortest distances from src to all other nodes.
    
*/

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
    // Create a visited array to keep track of processed nodes
    vector<bool> visited(adj.size(), 0);
    
    // Create a distance array and initialize all distances to infinity (INT_MAX)
    vector<int> dist(adj.size(), INT_MAX);

    // Distance to the source node is always 0
    dist[src] = 0;
    
    // Number of nodes in the graph
    int count = adj.size();

    // Iterate until all nodes are processed
    while(count--) {

        int node = -1, value = INT_MAX;

        // Find the unvisited node with the smallest known distance
        for(int i = 0; i < adj.size(); i++) {
            if(!visited[i] && dist[i] < value) {
                node = i;
                value = dist[i];
            }
        }

        // Mark the chosen node as visited
        visited[node] = 1;

        // Update distances of neighboring nodes
        for(int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i].first;  // Get neighbor node
            int weight = adj[node][i].second;    // Get edge weight
            
            // If the new path is shorter, update the distance
            if(!visited[neighbour] && dist[node] + weight < dist[neighbour])
                dist[neighbour] = dist[node] + weight;
        }
    }
    
    // Return the shortest distances from the source node to all other nodes
    return dist;
}


int main(){
    vector<vector<pair<int, int>>> adj = {
        {{1,1}, {2,6}},
        {{2,3}, {0,1}},
        {{1,3}, {0,6}},
    };
    
    int src = 2;

    vector<int> ans = dijkstra(adj, src);

    for(int i : ans)
        cout << i << " ";
}