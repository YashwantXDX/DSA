#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/topological-sort/1

    Refer Video :- https://www.youtube.com/watch?v=2JgYwQ6TZ44&t=2224s

    Topological Sorting for a Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge U -> V, the vertex U comes before V.
    
    We are using Kahn's Algorithm :-

    1. traverse all the node and get In Degree.
    2. Make a queue and push the nodes whose In Degree is 0.
    3. Now push that node into the answer and decrease the node's connections' In Degree by one.
    4. And check if anyu In Degree is gone 0, if yes, then push it into the queue.
    5. Follow 3 and 4 step till the queue is empty and finally return the answer.

*/

vector<int> topologicalSort(vector<vector<int>>& adj) {
    
    vector<int> ans;
    vector<int> inDegree(adj.size(), 0);
    queue<int> q;

    // Get The In Degree of All The Nodes
    for(int i = 0; i < adj.size(); i++)
        for(int j = 0; j < adj[i].size(); j++)
            inDegree[adj[i][j]]++;
    
    // Check for nodes whose in Degree is 0
    for(int i = 0 ; i < adj.size(); i++)
        if(inDegree[i] == 0)
            q.push(i);
    
    while(!q.empty()){

        // Get the front node of the queue
        int node = q.front(); q.pop();

        // Push the into the answer
        ans.push_back(node);

        // Now Check the connections of that node
        for(int i = 0; i < adj[node].size(); i++){

            // First decrease the node's connections' In Degree by One, as the node is deleted
            inDegree[adj[node][i]]--;

            // Now check if the connection has In Degree = 0, If it is, then just push that back into the queue
            if(inDegree[adj[node][i]] == 0)
                q.push(adj[node][i]);

        }
            

    }

    return ans;

}

int main(){

    vector<vector<int>> matrix = {
        {},
        {3},
        {3},
        {},
        {0,1},
        {0,2},    
    };
    
    vector<int> ans = topologicalSort(matrix);

    for(int i : ans)
        cout << i << " ";

}