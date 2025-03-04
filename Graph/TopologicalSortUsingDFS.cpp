#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/topological-sort/1

    Refer Video :- https://www.youtube.com/watch?v=2JgYwQ6TZ44

    Topological Sorting for a Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge U -> V, the vertex U comes before V.
    

*/

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s){

    // Node ko visited mark kar do
    visited[node] = true;

    // Node ke connections ko check kro
    for(int i = 0; i < adj[node].size(); i++){

        // Agar vo visited nhi hai to uss node ke liye dfs ko call kro
        if(!visited[adj[node][i]]){

            DFS(adj[node][i], adj, visited, s);

        }

    }

    // Vps aate time current node ko stack me push krva do
    s.push(node);

}

vector<int> topologicalSortUsingDFS(vector<vector<int>>& adj) {
    
    // DFS Wala Tareeka
    stack<int> s;
    vector<bool> visited(adj.size(), 0);
    vector<int> ans;

    // Check kro har node ko ki visited hai ya nhi
    for(int i = 0; i < adj.size(); i++){

        // Agar visited nhi hai to uske liye DFS function call kar do
        if(!visited[i]){

            DFS(i, adj, visited, s);

        }

    }

    // Har ek node visit krne ke baad hum, stack ko empty krenge
    while(!s.empty()){

        // Top element ko ans array me push kar denge
        ans.push_back(s.top());

        // Stack ke top ko htao
        s.pop();

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
    
    vector<int> ans = topologicalSortUsingDFS(matrix);

    for(int i : ans)
        cout << i << " ";

}