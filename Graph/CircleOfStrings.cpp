#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/circle-of-strings4530/1

    Refer Video :- https://www.youtube.com/watch?v=35WdIcEAZI0

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

// Function to check if a given set of strings can be arranged in a circular manner
int isCircle(vector<string> &arr) {
        
    // Create an adjacency list for 26 lowercase English letters (a-z)
    vector<int> adj[26];

    // Vectors to store in-degree and out-degree of each character
    vector<int> InDegree(26, 0);
    vector<int> OutDegree(26, 0);

    // Construct the graph from the given words
    for (int i = 0; i < arr.size(); i++) {

        // Store the current String in temp
        string temp = arr[i];

        // Convert first character of the string to an index (0-25)
        int u = temp[0] - 'a';

        // Convert last character of the string to an index (0-25)
        int v = temp[temp.size() - 1] - 'a';

        // Build adjacency list representation of the graph
        adj[u].push_back(v);

        // Increase in-degree for destination node
        InDegree[v]++;

        // Increase out-degree for source node
        OutDegree[u]++;
    }

    // Check if in-degree and out-degree of every character are the same
    for (int i = 0; i < 26; i++) {
        if (InDegree[i] != OutDegree[i])
            return 0; // Not an Eulerian Circuit
    }

    // Perform DFS traversal to check if the graph is connected

    // Visited array for DFS
    vector<bool> visited(26, false);

    // Start DFS from the first character of the first word
    DFS(arr[0][0] - 'a', adj, visited);

    // Check if all characters with non-zero degree are visited
    for (int i = 0; i < 26; i++) {
        if (InDegree[i] && !visited[i])
            return 0; // Not connected, so not an Eulerian Circuit
    }

    return 1; // Eulerian Circuit exists, so a circular arrangement is possible
}


int main(){

    vector<string> arr = {"ab", "bc", "cd", "da"};

    cout << "Circle Of String : " << isCircle(arr);

}