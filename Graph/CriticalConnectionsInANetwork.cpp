#include<bits/stdc++.h>
using namespace std;

/*

        VERY VERY IMPORTANT GRAPH QUESTION  

    Problem Link :- https://leetcode.com/problems/critical-connections-in-a-network/description/

    Refer Video :- https://www.youtube.com/watch?v=R_bFeK5MR6I

    Time Complexity :- O(V + E)
    Space Complexity :- O(V + E)

*/

void DFS(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &bridges, int &count){

    // Discovery or low of node current count ki value daal do
    disc[node] = count;
    low[node] = count;

    // Node ko visited mark kar do
    visited[node] = true;

    // Current node ke connections check kro
    for(int i = 0; i < adj[node].size(); i++){

        // Neighbour ko bahar nikaalo
        int neigh = adj[node][i];

        // Dekho kahi neighbour or parent same to nhi
        // agar hai to ignore kro use
        if(neigh == parent) continue;

        // Ab dekho ki kahi jko neighbour nikaale hai vo visited to nhi
        // agar visited hai means cycle present hai
        // uss case me hum simply node ka low hai use hum node orr neigh ke low me jo bhi minimum hai us se update kr do
        else if(visited[neigh])
            low[node] = min(low[node], low[neigh]);
        
        // Agar jo neighbour aaya hai vo na hi parent hai orr na hi visited hai
        // ek dam nya nvela hai to uss case pe ye kro
        else{

            // discovery count ek se increment kr do
            count++;

            // Ab neigbour ke liye DFS lgao orr parent me node ko rkho
            // because ab neighbour current node ban gya orr abhi jo current node tha vo parent ban gya
            DFS(neigh, node, adj, visited, disc, low, bridges, count);

            // Ab jo current node hai uske low ko 
            // neigh orr node ke low ne se jo bhi minimum hai uss se update kr do
            low[node] = min(low[node], low[neigh]);

            // Bridge exist krta hai means
            // agar low[neigh] > disc[node] se
            if(low[neigh] > disc[node]){

                // ek 1d array lo
                vector<int> temp;

                // usme neigh orr node ko push kr do
                temp.push_back(node);
                temp.push_back(neigh);

                // ab uss 1d array kio bridges me push kr do
                bridges.push_back(temp);
            }

        }
        
    }

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
    // Adjancey List
    vector<vector<int>> adj(n);

    for(int i = 0; i < connections.size(); i++){

        int x = connections[i][0]; // First node
        int y = connections[i][1];  // Second node

        // Add bi - directional edges because of undirected graph
        adj[x].push_back(y); // Add edges between x and y
        adj[y].push_back(x); // Add edges between y and x

    }

    // Future Use Vectors
    vector<bool> visited(n, false); // visited array to track the nodes
    vector<int> disc(n), low(n); // discovery array to get current node and low array to get low of the node

    vector<vector<int>> bridges; // Get the bridges as one node and second node

    int count = 0; // To keep track of the discovery Node

    // Call DFS as node, parent, visited, disc, low, bridges, count
    DFS(0, -1, adj, visited, disc, low, bridges, count);

    // Sare chiz hone ke baad bridges ko as an asnwer return kr do
    return bridges;

}


int main(){

    /*
    
            2
        1
            0
        3

        1 connected with 2 connected with 0 connected with 1 - Cycle
        3 connected with 1
    
    */

    vector<vector<int>> connections = {
        {0,1},
        {1,2},
        {2,0},
        {1,3}
    };

    int vertex = 4;

    vector<vector<int>> ans = criticalConnections(vertex, connections);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}