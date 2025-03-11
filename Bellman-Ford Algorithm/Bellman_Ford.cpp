#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

    Refer Video :- https://www.youtube.com/watch?v=6DCnv6Q3iwk

    Note :- This Algorithm is used when we have a Directed Weighted Graph and the weight can be negetive.

    Problem Logic :-
    1. We assume all locations are at a very large distance (infinity).
    2. We start from the given source location and set its distance to 0.
    3. We relax all roads N-1 times, meaning:
        i. If the distance from A to B through a certain road is shorter than the previously known distance, update it.
    4. After N-1 updates, if a shorter path is still found, a negative cycle exists.

    Algorithm Steps:-

    1. Initialize an array dist[] with ∞ (1e8), except for the source, which is set to 0.
    2. Repeat (N-1) times:
        i. For each road (u → v) with weight w, update:
            a. if dist[u] + w < dist[v], then dist[v] = dist[u] + w
    3. Check for Negative Cycles:
        i. If another update is possible, return -1 (negative cycle detected).
    4. Return the distance array as the shortest travel times.

*/

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    // Initialize distance array with a large value (1e8 represents infinity)
    vector<int> dist(V, 1e8);
    dist[src] = 0; // Distance from source to itself is 0

    // Perform (V - 1) iterations to relax all edges
    for(int i = 0; i < V - 1; i++){

        bool flag = 0; // Track if any update occurs in this iteration

        for(int j = 0; j < edges.size(); j++){

            // Extract edge details: start node (u), end node (v), and weight
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // Ignore if the distance to the starting node is still at infinity
            if(dist[u] == 1e8) continue;

            // If a shorter path is found, update the distance
            if(dist[u] + weight < dist[v]){
                flag = 1; // Mark that a change occurred
                dist[v] = dist[u] + weight; // Update the shortest distance
            }
        }

        // If no change occurs in this iteration, the shortest distances are finalized
        if(flag == 0)
            return dist;
    }

    // Check for negative-weight cycles
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Ignore if the distance to the starting node is still at infinity
        if(dist[u] == 1e8) continue;

        // If another update can be made, a negative-weight cycle exists
        if(dist[u] + weight < dist[v])
            return {-1}; // Return -1 to indicate a negative cycle
    }

    return dist; // Return the shortest distance array
}


int main(){
    vector<vector<int>> edges  = {
        {0,1,5},
        {1,0,3},
        {1,2,-1},
        {2,0,1}
    };
    
    int V = 3, src = 2;

    vector<int> ans = bellmanFord(V, edges, src);

    for(int i : ans)
        cout << i << " ";
}