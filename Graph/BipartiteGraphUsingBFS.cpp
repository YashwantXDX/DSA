#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/bipartite-graph/1

    Refer Video :- https://www.youtube.com/watch?v=gSCidfLIVGc

    Bipartite Graph is a graph in which the vertices can be divided into two disjoint sets, such that no 2 vertices within the same set are adjacent.
    
    In other words, it is a graph in which every edge connects a vertex of one set to a vertex of other set.

    Problem logic :- 

    Look all the neighbour of the current node

    If Color is not assigned then assigh a color to them with opposite of their parent node and push it into the queue

    If Color is assigned then check if the parent is also the same color or not, if the parent is same color then just return false, if not then just continue with the above step.


*/

bool isBipartite(vector<vector<int>>& adj) {
    
    // Get the color vector and queue ready
    // Initialize the color vector with -1 to show no color is assigned
    vector<int> color(adj.size(), -1);
    queue<int> q;

    // Check for every node in the plane
    for(int i = 0; i < adj.size(); i++){

        // Check if the current node is not colored
        if(color[i] == -1){

            // Push that into the queue and mark its color
            q.push(i);
            color[i] = 0;

            // Go till queue is not empty
            while(!q.empty()){

                // Fetch the front node from the queue
                int node = q.front(); q.pop();

                // Check its connections
                for(int j = 0; j < adj[node].size(); j++){

                    // If the connection node is not colored yet, then color it
                    if(color[adj[node][j]] == -1){

                        // Color the connection nodes with the color opposite of the parent node
                        if(color[node] == 1)
                            color[adj[node][j]] = 0;
                        
                        else
                            color[adj[node][j]] = 1;
                        
                        // Push the connection nodes into the queue
                        q.push(adj[node][j]);

                    }

                    // If the connection node is already colored
                    else{

                        // Check if the connection node is same as the color of the parent node, If yes then it is not a Barpartite Graph
                        if(color[adj[node][j]] == color[node])
                            return false;

                    }

                }

            }

        }

    }

    // If everything works okay, then it is a Barpartite Graph
    return true;

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