#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

    Refer Video :- https://www.youtube.com/watch?v=lUXl7GnH9xk&t=3302s

    Time Complexity :- O(V + E) Because We used Min Heap
    Space Complexity :- O(V)

    Problem Logic :-

    1. Select the vertex which is not explored yet and its distance is minimum among all the unexplored vertexes.

    2. Relax The Edges : 
        i. Look at your all the unexplored neighbour
        
        ii. if(dist[node] + weight < dist[neighbour]){

                dist[neighbour] = dist[node] + weight;

        }


    Algorithm Steps:

    1. Initialize Distance & Visited Arrays:

        i.Create dist[] and set all values to infinity (INT_MAX).
        ii. Set dist[src] = 0 (distance to the source is 0).
        iii. Create visited[] and set all values to false.
    
    2. Use a Min-Heap (Priority Queue):

        i. Push {0, src} into the heap (0 is the initial distance).
    
    3.Process Nodes Until Heap is Empty:

        i. Extract the node with the smallest distance.
        ii. If already visited, skip it.
        iii. Mark the node as visited.
    
    4. Update Distances for Neighbors:

        i. For each neighbor of the current node:
            a. If a shorter path is found, update dist[neighbor].
            b. Push {new distance, neighbor} into the heap.
    
    5. Repeat Until All Nodes Are Processed.

    6. Return the dist[] array containing the shortest paths.

    
    
*/

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    
    // Distance array, initialized with a large value (infinity)
    vector<int> dist(adj.size(), INT_MAX);
    
    // Visited array to keep track of processed nodes
    vector<bool> visited(adj.size(), 0);

    // Min-Heap (priority queue) to get the node with the smallest distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;

    // Distance to the source node is 0
    dist[src] = 0;

    // Push the source node into the priority queue
    p.push({0, src});

    while(!p.empty()) {

        // Get the node with the smallest distance
        int node = p.top().second; 
        p.pop();

        // If the node is already visited, skip it
        if(visited[node] == 1) 
            continue;

        // Mark the node as visited
        visited[node] = 1;

        // Check all neighbors of the current node
        for(int i = 0; i < adj[node].size(); i++) {

            int neighbour = adj[node][i].first;  // Neighbor node
            int weight = adj[node][i].second;    // Edge weight

            // If a shorter path is found, update the distance
            if(!visited[neighbour] && dist[neighbour] > dist[node] + weight) {

                dist[neighbour] = dist[node] + weight;

                // Push the updated distance into the priority queue
                p.push({dist[neighbour], neighbour});
            }
        }
    }

    // Return the shortest distances from the source node
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