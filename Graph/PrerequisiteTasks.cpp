#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

    Refer Video :- https://www.youtube.com/watch?v=gLJmbAV74Bs

    Problem Logiv :- 

    Use Kahn's Algorithm (Topological Sort) in this question.

    We have to just Check That this is Directed Acyclic Graph or not

*/

bool isPossible(int N, int P, vector<pair<int, int> >& tasks) {
    
    // Adjacency list representation of the graph
    vector<int> adj[N]; 

    // Stores the in-degree (number of incoming edges) for each node
    vector<int> InDegree(N, 0);

    // Building the adjacency list and computing in-degree of each node
    for(int i = 0; i < P; i++){
        adj[tasks[i].second].push_back(tasks[i].first); // Add edge from tasks[i].second → tasks[i].first
        InDegree[tasks[i].first]++; // Increase in-degree for the dependent task
    }

    // Queue to store nodes with zero in-degree (tasks with no dependencies)
    queue<int> q; 
    for(int i = 0; i < N; i++)
        if(InDegree[i] == 0)
            q.push(i); // Push nodes with no dependencies into the queue

    int count = 0; // Count of processed nodes

    // Perform Topological Sorting using Kahn's Algorithm (BFS approach)
    while(!q.empty()){
        
        int node = q.front(); 
        q.pop();
        
        count++; // Increase count of nodes processed
        
        // Reduce the in-degree of adjacent nodes
        for(int i = 0; i < adj[node].size(); i++){
            
            InDegree[adj[node][i]]--;
            
            // If in-degree becomes zero, push it into the queue
            if(InDegree[adj[node][i]] == 0)
                q.push(adj[node][i]);
            
        }
    }

    // If count of processed nodes is equal to total nodes, return true (DAG exists)
    return count == N;

}

int main(){

    vector<pair<int,int>> tasks = {make_pair(1,0),make_pair(2,1),make_pair(3,2)};

    cout << isPossible(4,3,tasks);

}