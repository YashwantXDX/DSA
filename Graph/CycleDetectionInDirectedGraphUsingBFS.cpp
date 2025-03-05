#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Refer Video :- https://www.youtube.com/watch?v=sPlN86EpjJA&t=3637s

    Problem Logic :- 

    This algorithm is based on **Kahn’s Algorithm (Topological Sorting Approach)** to detect cycles in a **Directed Graph**.

    1. **Create an In-Degree Array:**  
    - Count the number of incoming edges for each node and store them in an `InDegree` array.

    2. **Initialize a Queue:**  
    - Add all nodes with `InDegree = 0` (nodes with no incoming edges) to a queue.

    3. **Process Nodes from the Queue:**  
    - While the queue is not empty:  
        - Remove the front node from the queue.  
        - Increase the count of processed nodes.  
        - Decrease the `InDegree` of its connected nodes.  
        - If any connected node's `InDegree` becomes 0, add it to the queue.  

    4. **Check for a Cycle:**  
    - If all nodes are processed (`count == total nodes`), there is **no cycle** → return `false`.  
    - If some nodes remain unprocessed (`count < total nodes`), there is a **cycle** → return `true`.  


*/

bool isCyclic(vector<vector<int>> &adj) {
    
    // Make A InDegree Vector to store the In Degree of the nodes
    vector<int> InDegree(adj.size(), 0);

    // Count the In Degree of the nodes
    for(int i = 0; i < adj.size(); i++)
        for(int j = 0; j < adj[i].size(); j++)
            InDegree[adj[i][j]]++;

    // Make a queue to store the Nodes whose In Degree count is 0
    queue<int> q;

    // Now get the nodes with In Degree 0 and push it into the queue
    for(int i = 0; i < adj.size(); i++){

        if(InDegree[i] == 0){

            q.push(i);

        }

    }

    // MAke a variable to store the count
    int count = 0;

    // Go till the queue is not empty
    while(!q.empty()){

        // Fetch the front node in the queue
        int node = q.front(); q.pop();

        // Increase the count
        count++;

        // Check the Connections of the node
        for(int i = 0; i < adj[node].size(); i++){

            // Decrease the In Degree of the node's Conncections by 1
            InDegree[adj[node][i]]--;

            // Check if the node's connection In Degree has gone 0?, If Yes, then push it into the queue
            if(InDegree[adj[node][i]] == 0){

                q.push(adj[node][i]);

            }

        }

    }

    // Now we need to check if all of the nodes are traversed in the graph.
    // If We can traverse all the nodes means count should be equal to the size of the adjacency list, we can say that there was no cycle present.
    // But If we cannot traverse all the nodes in the list before the queue goes empty, we can say that count will never be equal to the adjacency list size, so we can say that there is a cycle present
    // that is why we have to return count != adj.size()
    return count != adj.size();
        
}

int main(){

    vector<vector<int>> matrix = {
        {1},
        {2},
        {3},
        {3}   
    };
    
    cout << isCyclic(matrix);

    
}