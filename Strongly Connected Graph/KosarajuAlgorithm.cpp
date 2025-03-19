#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

    Refer Video :- https://www.youtube.com/watch?v=9VYiCAJ0mI8

    Time Complexity :- O(V + E)
    Space Complexity :- O(V + E)

    Problem Logic :-

    Understanding the Problem :

    We have a directed graph (a graph where edges have directions). We want to find the Strongly Connected Components (SCCs) of this graph.
    A Strongly Connected Component (SCC) is a group of nodes where:

    Every node can reach every other node in that group.
    To do this, we use Kosaraju’s Algorithm, which works in two passes using Depth First Search (DFS).

    Step-by-Step Logic :

    Step 1: Perform Topological Sorting

        Traverse the graph using DFS and store nodes in a stack in the order of their finishing times (when DFS is completely done for a node).
        This helps to process the nodes in the correct order for the next step.

    Step 2: Reverse the Graph

        Create a new graph by reversing the edges (i.e., if A → B existed, we make it B → A).
        This helps in finding SCCs.

    Step 3: Perform DFS on the Reversed Graph

        Pop nodes one by one from the stack and perform DFS on the reversed graph.
        Each DFS call finds one SCC.
        Keep counting SCCs.

    Explanation of the Code :

    Topological Sorting (TopologicalSort function) : This function does DFS and stores nodes in a stack after visiting all their neighbors.

    DFS Traversal (DFS function) : This function is a standard DFS used to explore nodes in the reversed graph.

    Main Function (kosaraju function) :-

        Step 1: Calls TopologicalSort for all unvisited nodes.
        Step 2: Reverses the graph by flipping all edges.
        Step 3: Uses DFS again on the reversed graph, using the stack to determine the order of nodes.
        Step 4: Counts the number of DFS calls on the reversed graph, which gives the number of SCCs.
        
    Final Output : The function returns the number of Strongly Connected Components (SCCs) in the given graph.

*/

void TopologicalSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s){

    // mark the node as visited
    visited[node] = true;

    // Check the Connections
    for(int i = 0; i < adj[node].size(); i++){

        // Get the neighbour of the node
        int neigh = adj[node][i];

        // Agar neighbour visited nhi hai to uske liye Topological Sort lgao
        if(!visited[neigh])
            TopologicalSort(neigh, adj, visited, s);

    }

    // Current node ko stack ke andar push kro
    s.push(node);
        
}

void DFS(int node, vector<bool> &visited, vector<vector<int>> &adj){

    // mark the node as visited
    visited[node] = true;

    // Check the Connections
    for(int i = 0; i < adj[node].size(); i++){

        // Get the neighbour of the node
        int neigh = adj[node][i];

        // Agar neighbour visited nhi hai to uske liye DFS lgao
        if(!visited[neigh])
            DFS(neigh, visited, adj);

    }

}

int kosaraju(vector<vector<int>> &adj) {
    
    // Topological Sort lgao DFS Method
    stack<int> s;

    // Number of Vertexes in the Graph
    int V = adj.size();    

    // INT MAX because nodes are not given
    vector<bool> visited(V, false);

    // Har ek node me jao topological ke liye
    for(int i = 0; i < V; i++)
        if(!visited[i])
            TopologicalSort(i, adj, visited, s);

    // Get the SCC count variable
    int SCC = 0;

    // Remark the visited vector to false
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Reverse The Edges of the graph

    // Make a new 2d Adjacency List with Reversed edges
    vector<vector<int>> adjReversed(V);

    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){

            // Grab the current node
            int x = i;

            // Grab its Number of connections
            int y = adj[i][j];

            // Now Reverse the Edges of the nodes with the connections
            adjReversed[y].push_back(x);

        }
    }

    // Empty the stack, one by one
    //      if the node is not visited then
    //          increase the SCC and call the DFS for that node

    while(!s.empty()){

        // Top nikaal ke pop kro
        int node = s.top(); s.pop();

        // If the node is not visited, call the DFS for it
        if(!visited[node]){

            // Increase the count of SCC
            SCC++;

            // Call the DFS for that node
            DFS(node, visited, adjReversed);
        }

    }

    // Return the SCC
    return SCC;

}

int main(){

    vector<vector<int>> adj = {
        {2,3},
        {0},
        {1},
        {4},
        {}
    };

    cout << "Number of Strongly Connected Components : " << kosaraju(adj);

}