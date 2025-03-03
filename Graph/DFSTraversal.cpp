#include <bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

    Refer Video :- https://www.youtube.com/watch?v=Vtu7qgF0ksw&t=2647s

    NOTE :- This code is only for Connected Graphs.

*/

// Recursive Way
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans)
{

    // Mark the node as visited
    visited[node] = 1;

    // Push back the answer
    ans.push_back(node);

    // Check for the nodes connections
    for (int i = 0; i < adj[node].size(); i++)
    {

        // If not visited
        if (!visited[adj[node][i]])
        {

            // Call the function back for that node
            DFS(adj[node][i], adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{

    vector<int> ans;
    vector<bool> visited(adj.size(), 0);

    DFS(0, adj, visited, ans);

    return ans;
}

vector<int> dfsOfGraph2(vector<vector<int>> &adj)
{

    stack<int> s;
    vector<int> ans;
    vector<bool> visited(adj.size(), 0);

    // By Default push the 0
    s.push(0);
    
    while(!s.empty()){

        // Take the top element of the stack
        int temp = s.top(); s.pop();

        // Check if that element is visited or not
        if(!visited[temp]){
            visited[temp] = 1;
            ans.push_back(temp);
        }

        // We have to start from the back
        for(int i = adj[temp].size() - 1; i >= 0; i--){

            // Check is the node is visited or not
            if(!visited[adj[temp][i]]){

                // Push that element into the stack
                s.push(adj[temp][i]);

            }

        }

    }

    return ans;
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2},
        {0, 7, 5},
        {0, 3, 4},
        {2},
        {2},
        {1, 6},
        {5, 8},
        {1, 8},
        {6, 7}};

    vector<int> ans = dfsOfGraph(matrix);

    for (int i : ans)
        cout << i << " ";
}