#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=EYM_lIVYJak&t=3726s

    Time Complexity :- O(M ^ N)
    Space Complexity :- O(V + E)

    Problem Logic :- 

    Graph Representation :

        We represent the graph using an adjacency list (adj[]), where each node stores its list of neighbors.

        A color[] array is used to store the assigned color of each node, initially set to -1 (uncolored).

    Recursive Function (find) :

        The function find(node, adj, color, m, v) attempts to color nodes one by one.

        Base Condition: If all nodes are colored (node == v), return true.

        Loop through m colors: Try assigning a color to the current node.

        Check neighbors: Ensure no adjacent node has the same color.

        Recursive Call: Move to the next node (node + 1) and repeat the process.

        Backtracking: If no valid color is found, reset the color and try the next one.

    Graph Coloring Function (graphColoring) :

        Builds the adjacency list from the given edges.

        Calls find() on each uncolored node to start the coloring process.

        If find() returns false, it means the graph cannot be colored with m colors.

*/

bool find(int node, vector<int> adj[], vector<int> &color, int &m, int &v){

    // Base Condition : Agar sare nodes pe color ho jata hai
    // means agar node , size tk aa gya mtlb ho skta hai
    if(node == v)
        return true;

    // Colors dekho
    for(int i = 0; i < m; i++){

        // coloring flag
        bool flag = true;

        // neighbours ka color dekho
        for(int j = 0; j < adj[node].size(); j++){

            // agar kisi connection ka color same aata hai to phir node color nhi ho skta, change kro
            if(color[adj[node][j]] == i){

                flag = false;

                break;

            }

        }

        // color assign ho skta hai
        if(flag == true){
            
            color[node] = i;

            // ab cuurent node ke aage wale ke liye DFS call kro
            // true aaya mtlb connections me color assign ho skte hai
            if(find(node + 1, adj, color, m, v))
                return true;
            
            // agar false aaya, mtlb color assign nhi ho skta, to back track krna pdega
            // means current color ko unassign kr do
            color[node] = -1;

        }

    }   

    // Koi color assign nhi ho skta
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
        if(color[i] == -1 && !find(i, adj, color, m, v))
            return false;
    
    return true;
    
}

int main(){

    vector<pair<int, int>> edges = {
        {0,1},
        {1,2},
        {0,2}
    };

    int v = 3, m = 2;

    cout << graphColoring(v, edges, m);

}