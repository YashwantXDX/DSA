#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    Refer Video :- https://www.youtube.com/watch?v=oz1EaP_Bw4s&t=2762s

    BFS Traversal is Used

*/

bool BFS(int node, vector<vector<int>> &mat, vector<bool> &visited){

    // Make a Queue for BFS Traversal
    queue<pair<int, int>> q;

    // Mark the current node as visited
    visited[node] = true;

    // Push in the pair of child and parent
    q.push(make_pair(node, -1));;
    
    while(!q.empty()){

        // Retrieve the Child and Parent from the queue
        int child = q.front().first;
        int parent = q.front().second;

        // Remove the front of the queue
        q.pop();

        // Check its connections
        for(int i = 0; i < mat[child].size(); i++){

            // If the current connection is same as parent then just ignore
            if(parent == mat[child][i]) continue;

            // If we found the current element visited, then just return true as cycle is detectec
            if(visited[mat[child][i]]) return true;

            // If everthing is fine then just mark the current element as visited
            visited[mat[child][i]] = true;

            // Make the pair of the current element as the child and the the current child as parent
            q.push(make_pair(mat[child][i], child));

        }

    }

    return false;
}

bool isCycle(vector<vector<int>> &adj){

    // Visited Array
    vector<bool> visited(adj.size(), 0);

    // Check All the elements visited
    for(int i = 0; i < adj.size(); i++){

        // If any node is found unvisited and that node has cycle in it
        if(!visited[i] && BFS(i, adj, visited))
            return true;

    }

    return false;

}

int main(){

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
    
    cout << "Cycle ? :- " << isCycle(matrix);


}