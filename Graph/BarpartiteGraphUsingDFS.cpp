#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/bipartite-graph/1

    Refer Video :- https://www.youtube.com/watch?v=gSCidfLIVGc

    Bipartite Graph is a graph in which the vertices can be divided into two disjoint sets, such that no 2 vertices within the same set are adjacent.
    
    In other words, it is a graph in which every edge connects a vertex of one set to a vertex of other set.

    Problem logic :- 

    Look all the neighbour of the current node

    If Color is not assigned then assigh a color to them with opposite of their parent node and recursive call the function for that node

    If Color is assigned then check if the parent is also the same color or not, if the parent is same color then just return false, if not then just continue with the above step.


*/

bool checkBarpartite(int node, vector<vector<int>> &adj, vector<int> &color){

    // Check for the node's connections
    for(int i = 0; i < adj[node].size(); i++){

        // If the current connection is not assigned any color
        if(color[adj[node][i]] == -1){

            // Assign the current connection node the color opposite to the parent color
            if(color[node] == 1)
                color[adj[node][i]] = 0;
            
            else
                color[adj[node][i]] = 1;
            
            // Recursive call for that current connection
            // If any of the nodes return false for the fumction , then it is not barpartite
            if(!checkBarpartite(adj[node][i], adj, color))
                return false;

        }

        // If the current connection is assigned a color
        else{

            // Check if the color is same or not as the parent
            // If same then it is not barpartite
            if(color[node] == color[adj[node][i]])
                return false;

        }

    }

    // If Everything goes fine, then it is the barpartite graph
    return true;

}

bool isBipartite(vector<vector<int>>& adj) {
    
    // Initialize the color vector with -1 to show no color is assigned
    vector<int> color(adj.size(), -1);

    // Go through every node of the graph
    for(int i = 0; i < adj.size(); i++){

        // Check if the color is assigned or not, If not assigned then assign the color
        if(color[i] == -1){

            color[i] = 0;
            
            // Call the function to check for the node and its neighbours
            // If any of the node's neighbour is same as parent then it is not Barpartite
            if(!checkBarpartite(i, adj, color)) return false;
        }

    }

    // If everything goes fine
    return true;;

}

int main(){

    vector<vector<int>> matrix = {
        {1},
        {0,2,3},  
        {1},  
        {1,4,5,8},  
        {3},  
        {3,6},  
        {5,7},  
        {6,8},
        {3,7}  
    };
    
    cout << isBipartite(matrix);

}