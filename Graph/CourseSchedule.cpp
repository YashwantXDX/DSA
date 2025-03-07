#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/course-schedule/1

    Refer Video :- https://www.youtube.com/watch?v=gLJmbAV74Bs&t=1045s

    Problem Logic :- 

    Use Kahn's Algorithm (Topological Sort) in this question.

    We have to just Check That this is Directed Acyclic Graph or not.

*/

vector<int> findOrder(int n, int m, vector<vector<int>> tasks) 
{
    // Adjacency list representation of the graph
    vector<int> adj[n]; 
    
    // Stores the in-degree (number of incoming edges) for each node
    vector<int> InDegree(n, 0); 
    
    // Stores the result (Topological order)
    vector<int> ans;

    // Building the adjacency list and computing in-degree of each node
    for(int i = 0; i < m; i++){
        adj[tasks[i][1]].push_back(tasks[i][0]); // Add directed edge tasks[i][1] → tasks[i][0]
        InDegree[tasks[i][0]]++; // Increase in-degree for the dependent task
    }

    queue<int> q;

    // Push nodes with zero in-degree (tasks with no dependencies) into the queue
    for(int i = 0; i < n; i++){
        if(InDegree[i] == 0)
            q.push(i);
    }

    // Perform BFS-based Topological Sorting
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        ans.push_back(node); // Add node to the topological order
        
        // Reduce the in-degree of adjacent nodes
        for(int i = 0; i < adj[node].size(); i++){
            InDegree[adj[node][i]]--;

            // If in-degree becomes zero, push it into the queue
            if(InDegree[adj[node][i]] == 0)
                q.push(adj[node][i]);
        }
    }

    // If all nodes are included in the topological order, return it
    // Otherwise, return an empty vector (indicating a cycle exists)
    return ans.size() == n ? ans : vector<int>();
}


int main(){

    vector<vector<int>> mat = {{1,0}};

    vector<int> ans = findOrder(2,1,mat);
    for(int i : ans)
        cout << i << " ";

}