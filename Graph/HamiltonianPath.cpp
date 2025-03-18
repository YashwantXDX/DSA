#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1

    Refer Video :- https://www.youtube.com/watch?v=zjwL3Tw-ko8

    Time Complexity : O(N!)

    Space Complexity : O(N + M)

*/

bool DFS(int node, vector<int> adj[], vector<bool> &visited, int &count, int &N){

    // Node ko visited mark kar ke count increase kr do
    visited[node] = true;
    count++;

    // Base Case : Agar hum ne sare nodes cover kr liya hai
    // mtlb hume hamiltonian path mil gya hai
    if(count == N)
        return 1;

    // Connections ko check kro
    for(int i = 0; i < adj[node].size(); i++){

        // Neighbour node nikaalo
        int neigh = adj[node][i];

        // agar neighbour node visited nhi hai orr uss node se hum baki bache node connect kr skte hai 
        // mtlb hume path mil gya hai
        if(!visited[neigh] && DFS(neigh, adj, visited, count, N))
            return true;

    }

    // Agar current node se hum baki nodes ko connect nhi kr paa rhe
    // uss case me hume backtracking krna hai

    // visited ko false mark kro orr count ko decrease kr do ek se
    visited[node] = false;

    count--;

    // return karo false because uss node se hum nhi connect kr skte
    return false;
}

bool check(int N,int M,vector<vector<int>> Edges)
{
    // Adjacency List bnao
    vector<int> adj[N];

    for(int i = 0; i < M; i++){

        // Convert the 1 based index into 0 based index
        int x = Edges[i][0] - 1;
        int y = Edges[i][1] - 1;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    // Visited array to keep track of nodes
    vector<bool> visited(N, false);

    // count to keep track of the count of nodes visited
    int count = 0;

    // Call DFS function for all nodes to get the Hamiltonian Path
    for(int i = 0; i < N; i++){

        // agar kahi se bhi hum ek node se sare node pe jaa skte hai
        // bina koi node ko revisit kiye
        // means hamiltonian path mil gya hai
        if(DFS(i, adj, visited, count, N))
            return true;
    }

    // Nhi mila kuch
    return false;
    
}

int main(){

    vector<vector<int>> edges = {
        {1,2},
        {2,3},
        {3,4},
        {2,4},
    };

    int N = 4, M = 4;

    cout << check(N, M, edges);

}