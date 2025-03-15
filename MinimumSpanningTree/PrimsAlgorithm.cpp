#include<bits./stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

    Refer Video :- https://www.youtube.com/watch?v=60WK9IFnFrg

    Time Complextity :- O(ElogV)
    Space Complextity :- O(V + E)

*/

int spanningTree(int V, vector<vector<int>> adj[]) {
    
    // Min heap (priority queue) to store edges in ascending order of weights
    // Each entry in the heap contains {weight, {current_node, parent_node}}
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> p;

    // Array to track whether a node is included in the Minimum Spanning Tree (MST)
    vector<bool> isMST(V, false);

    // Array to store the parent of each node in the MST (useful for constructing the tree)
    vector<int> parent(V);

    // Variable to store the total cost of the Minimum Spanning Tree
    int cost = 0;

    // Start from any node, here we choose node 0
    // The weight of the first node is 0, and its parent is -1 (no parent)
    p.push({0, {0, -1}});

    while (!p.empty()) {

        // Extract the edge with the smallest weight
        int weight = p.top().first;
        int node = p.top().second.first;
        int par = p.top().second.second;

        // Remove the top element from the priority queue
        p.pop();

        // If the node is not already in the MST, add it
        if (!isMST[node]) {

            // Mark the node as part of the MST
            isMST[node] = true;

            // Add the weight of this edge to the total cost
            cost += weight;

            // Store the parent of the node (useful for tree construction)
            parent[node] = par;

            // Traverse all adjacent nodes
            for (int i = 0; i < adj[node].size(); i++) {

                // Get the adjacent node and its edge weight
                int currNode = adj[node][i][0];
                int currWeight = adj[node][i][1];

                // If the adjacent node is not already in the MST, push it into the priority queue
                if (!isMST[currNode]) {
                    p.push({currWeight, {currNode, node}});
                }
            }
        }
    }

    // Return the total cost of the Minimum Spanning Tree
    return cost;
}


int main(){

    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5}); 

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1}); 

    cout << spanningTree(V, adj);

}