#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

    Refer Video :- https://www.youtube.com/watch?v=3BJTw_OWvTU

    Problem Logic That :- 

    1. Euler Circuit :
        i. Calculate the Degree of each node
        ii. All node should have even degree
        iii. All non-zero degree node should be connected

    2. Euler Path
        i. Calculate the Degree of each node
        ii. Zero or Two nodes can have odd degree and remaining have even degree
        iii. All non-zero degree node should be connected

*/

// Depth First Search (DFS) function to check graph connectivity
void DFS(int node, vector<int> adj[], vector<bool> &visited) {
    // Mark the current node as visited
    visited[node] = true;

    // Traverse all adjacent nodes
    for (int i = 0; i < adj[node].size(); i++) {
        // If the adjacent node is not visited, perform DFS on it
        if (!visited[adj[node][i]]) {
            DFS(adj[node][i], adj, visited);
        }
    }
}

// Function to check if a graph has an Euler Circuit or Euler Path
int isEulerCircuit(int V, vector<int> adj[]) {
    
    // Vector to store in-degrees of each vertex
    vector<int> inDegree(V, 0);

    // Count of vertices with an odd degree
    int oddDegree = 0;

    // Calculate in-degree for each vertex and count odd-degree vertices
    for (int i = 0; i < V; i++) {
        inDegree[i] = adj[i].size();
        if (inDegree[i] % 2 == 1) 
            oddDegree++;
    }

    // If the number of vertices with odd degree is not 0 or 2,
    // it means the graph is neither an Euler Path nor an Euler Circuit
    if (oddDegree != 0 && oddDegree != 2)
        return 0;

    // Vector to track visited nodes for connectivity check
    vector<bool> visited(V, false);

    // Perform DFS traversal to check graph connectivity
    for (int i = 0; i < V; i++) {
        // Start DFS from the first vertex with a non-zero degree
        if (inDegree[i] != 0) {
            DFS(i, adj, visited);
            break;
        }
    }

    // Check if all vertices with a non-zero degree are visited
    for (int i = 0; i < V; i++) {
        // If a vertex has a degree but is not visited, 
        // the graph is neither an Euler Path nor an Euler Circuit
        if (inDegree[i] && visited[i] == false)
            return 0;
    }

    // If all vertices have even degrees, it is an Euler Circuit
    if (oddDegree == 0) return 2;

    // Otherwise, it is an Euler Path
    return 1;
}


int main(){

    vector<int> adj[] = {
        {0, 1},
        {0, 2},
        {1, 2},
    };

    int V = 3;

    cout << isEulerCircuit(V, adj);

}