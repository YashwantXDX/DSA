#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=EYM_lIVYJak&t=3726s

    Time Complexity :- O(M * N) ^ N
    Space Complexity :- O(N)

    Problem Logic :- 

    Graph Representation :

        The graph is represented as an adjacency list (adj[]), where each node stores a list of its neighboring nodes.

        A color[] array is used to keep track of the assigned color for each node. Initially, all nodes are uncolored (-1).

    Depth First Search (DFS) for Coloring :

        The function DFS(node, adj, color, m) is used to assign colors to the nodes.

        It tries to assign one of m colors to the current node.

        Before assigning a color, it checks if the color is safe (i.e., no neighbor has the same color).

        If a valid color is found, the node is colored, and DFS continues to the next node.

    Backtracking Approach :

        If a valid color assignment is not possible for the next node, the function backtracks and changes the current node's color to try a different one.

        If no color works, it returns false, indicating the graph cannot be colored with m colors.

    Main Function (graphColoring) :

        Converts the edges into an adjacency list (adj[]).

        Calls DFS() for every uncolored node.

        If all nodes are successfully colored, return true; otherwise, return false.

*/

bool DFS(int node, vector<int> adj[], vector<int> &color, int &m){
        
    // check every color
    for(int i = 0; i < m; i++){
        
        // coloring flag
        bool flag = true;
        
        // check every neighbour
        for(int j = 0; j < adj[node].size(); j++){
                
            // if color is same as node then put the flag false and break the loop to change the color
            if(color[adj[node][j]] == i){
                flag = false;
                break;
            }
            
        }
        
        if(flag == false) continue;
        
        // if is is possible to color the node then color it
        color[node] = i;
        
        // we are using flag to color the neighbour too
        flag = true;
        
        for(int j = 0; j < adj[node].size(); j++){
            
            // agar koi color assign nhi hai orr DFS false return kr rha hai
            // mtlb hum koi color assign nhi kr skte abhi
            if(color[adj[node][j]] == -1 && !DFS(adj[node][j], adj, color, m)){
                
                flag = false;
                break;
                
            }
            
        }
        
        // agar color assign ho skte hai
        if(flag == true) return true;
        
        // agar nhi ho skta to back track kro orr color ko unassign kro taaki change ho skte
        color[node] = -1;
        
    }
    
    // not possible yet to assign the color
    return false;
    
}

bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    
    // coloring vector
    vector<int> color(v, -1);
    
    // Adjacency List
    vector<int> adj[v];
    
    for(int i = 0; i < edges.size(); i++){
        
        int edge1 = edges[i].first;
        int edge2 = edges[i].second;
        
        adj[edge1].push_back(edge2);
        adj[edge2].push_back(edge1);
        
    }
    
    // check each node
    for(int i = 0; i < v; i++)
        if(color[i] == -1 && !DFS(i, adj, color, m))
            return false;
    
    return true;
    
}

int main(){

    vector<pair<int, int>> edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,0},
        {0,2}
    };

    int v = 4, m = 3;

    cout << graphColoring(v, edges, m);

}